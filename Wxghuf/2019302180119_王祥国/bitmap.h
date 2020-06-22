//
//    bitmap.h
// 
//   国家网络安全学院
//   2019302180119 
//  王祥国 2020/5/30

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define HEADER_SIZE 14
#define INFO_SIZE 40
#define realrow(x) (4 * ceil((double)(x) * 8 / 32))

typedef struct {
    unsigned bfType:16;
    unsigned bfSize;
    unsigned bfReserved1:16;
    unsigned bfReserved2:16;
    unsigned bfOffBits;
} BitmapHeader;

typedef struct {
    unsigned biSize;
    unsigned biWidth;
    int biHeight;
    unsigned biPlanes:16;
    unsigned biBitCount:16;
    unsigned biCompression;
    unsigned biSizeImage;
    unsigned biXPelsPerMeter;
    unsigned biYPelsPerMeter;
    unsigned biClrUsed;
    unsigned biClrImportant;
    unsigned biOtherDataSize;
    char *biOtherData;
} BitmapInfo;

typedef struct BMP {
    unsigned raw_size;
    // the total size(including padding) of data field
    BitmapHeader *header;
    // the header structure
    BitmapInfo *info;
    // the information structure
    unsigned palette_size;
    unsigned *palette_ptr;
    // to pointer to palette
    unsigned char *content_ptr;
    // the pointer to pure data
    unsigned int (*getPixel)(struct BMP *, int, int);
    void (*bitmapDestroy)(struct BMP *);
} Bitmap;

typedef struct HUFFBMP {
    Bitmap *bitmap;
    unsigned int weight[256];
    unsigned int code_length[256];
    unsigned char huffcodes[256][256];
    void (*huffmanEncode)(struct HUFFBMP *encoding_huffmap);
    int (*writeFile)(struct HUFFBMP *, char *filename);
    void (*huffmapDestroy)(struct HUFFBMP *);
} Huffmap;

typedef struct {
    unsigned color_data:8;
    char huffcodes[256];
    int code_length;
    int weight;
    int parent;
    int left_child;
    int right_child;
} HuffNode;

void _startInput(char *filename);
Huffmap *initHuffmap(char *filename);
Bitmap *_openBitmap(char *filename);
unsigned int _getPixel(Bitmap *, int X, int Y);
int _writeFile(struct HUFFBMP *, char *filename);
void _huffmanEncode(Huffmap *encoding_huffmap);
void _concatBinary(unsigned char *src, unsigned char *bin, unsigned length, unsigned orign_length);
void _setBit(unsigned char *src, unsigned bit, unsigned pos);
void _huffmapDestroy(struct HUFFBMP *);
void _bitmapDestroy(Bitmap *);

Huffmap *initHuffmap(char *filename) {
    Huffmap *huffmap = (Huffmap *) malloc(sizeof(Huffmap));
    huffmap->bitmap = _openBitmap(filename);
    huffmap->huffmapDestroy = _huffmapDestroy;
    huffmap->writeFile = _writeFile;
    huffmap->huffmanEncode = _huffmanEncode;
    
    int x_max = huffmap->bitmap->info->biWidth;
    int y_max = huffmap->bitmap->info->biHeight;
    unsigned int index = 0;
    
    for (int i = 0; i < y_max; ++i) {
        for (int j = 0; j < x_max; ++j) {
            index = huffmap->bitmap->getPixel(huffmap->bitmap, j, i);
            huffmap->weight[index]++;
        }
    }
    return huffmap;
}

Bitmap *_openBitmap(char *filename) {
    Bitmap *map = (Bitmap *) malloc(sizeof(Bitmap));
    map->bitmapDestroy = _bitmapDestroy;
    map->getPixel = _getPixel;
    map->header = (BitmapHeader *) malloc(sizeof(BitmapHeader));
    map->info = (BitmapInfo *) malloc(sizeof(BitmapInfo));
    // the pointer to extire file structure

    FILE *file = fopen(filename, "rb");
    // file describer for our bmp file
    assert(file != NULL);
    fread(map->header, 1, HEADER_SIZE, file);

    // read data from file for further analyse
    fread(map->info, 1, INFO_SIZE, file);
    
    printf("Target File:%s\nAnalyzing...\n", filename);
    printf("          IMAGE ATTRIBUTION\n");
    printf("------------------------------------\n");
    printf("|       Image Pixel Depth: %2d      |\n", map->info->biBitCount);
    printf("------------------------------------\n");
    printf("|  Height:%6d  |  Width:%6d  |\n", map->info->biHeight, map->info->biWidth);
    printf("------------------------------------\n");
    printf("|  palette Found, Clr Number: %3d  |\n", map->info->biClrUsed == 0 ? 1 << map->info->biBitCount : map->info->biClrUsed);
    printf("------------------------------------\n");
    
    map->palette_size = (unsigned int) pow(2, map->info->biBitCount);
    map->palette_ptr = (unsigned *) malloc(map->palette_size * sizeof(int));
    
    if (map->info->biSize > INFO_SIZE) {
        map->info->biOtherDataSize = map->info->biSize - INFO_SIZE;
        map->info->biOtherData = (char *) malloc(map->info->biOtherDataSize);
        fread(map->info->biOtherData, 1, map->info->biOtherDataSize, file);
    } else {
        map->info->biOtherDataSize = 0;
    }

    fread(map->palette_ptr, 1, 4 * map->palette_size, file);
    // read pallette to memory
    
    map->raw_size = map->info->biHeight * realrow(map->info->biWidth);
    assert(map->raw_size == map->info->biSizeImage);
    printf("|  BitMap Size:%8d, 0x%-8x|\n", map->raw_size, map->raw_size);
    printf("------------------------------------\n");
    
    map->content_ptr = (unsigned char *) malloc(map->raw_size);
    if (fread(map->content_ptr, 1, map->raw_size + 1, file) != map->raw_size) {
        printf("File corrupt.\n");
        map->bitmapDestroy(map);
        exit(1);
    }
    map->header->bfSize = ftell(file);
    printf("Image Successfully Loaded.\n");
    return map;
}

unsigned int _getPixel(Bitmap *map, int X, int Y) {
    assert(X < map->info->biWidth && Y < map->info->biHeight && X >= 0 && Y >= 0);
    int real_line = realrow(map->info->biWidth);
    unsigned int res = *(map->content_ptr + X + Y * real_line);
    return res;
}

void _huffmanEncode(Huffmap *encoding_huffmap) {
    printf("Huffman encoding...\n");
    HuffNode huffnode[512];
    for (int i = 0; i < 256; i++) {
        huffnode[i].color_data = i;
        huffnode[i].weight = encoding_huffmap->weight[i];
        huffnode[i].left_child = huffnode[i].right_child = huffnode[i].parent = -1;
    }
    for (int i = 256; i < 511; i++) {
        int minimum_1 = 0x7fffffff;
        int minimum_2 = 0x7fffffff;
        int leftnode = 0;
        int rightnode = 0;
        
        for (int j = 0; j < i; j++) {
            if (huffnode[j].parent == -1) {
                if (huffnode[j].weight < minimum_1) {
                    minimum_2 = minimum_1;
                    rightnode = leftnode;
                    minimum_1 = huffnode[j].weight;
                    leftnode = j;
                }
                else if (huffnode[j].weight < minimum_2) {
                    minimum_2 = huffnode[j].weight;
                    rightnode = j;
                }
            }
        }
        huffnode[i].parent = -1;
        huffnode[i].left_child = leftnode;
        huffnode[i].right_child = rightnode;
        huffnode[i].weight = huffnode[leftnode].weight + huffnode[rightnode].weight;
        huffnode[leftnode].parent = huffnode[rightnode].parent = i;
    }
    huffnode[510].code_length = 0;
    
    for (int i = 510; i >= 256; i--) {
        int fatherlength = huffnode[i].code_length;
        int leftchild = huffnode[i].left_child;
        int rightchild = huffnode[i].right_child;
        huffnode[leftchild].code_length = huffnode[rightchild].code_length = fatherlength + 1;
        for (int j = 0; j < fatherlength; j++) {
            huffnode[leftchild].huffcodes[j] = huffnode[rightchild].huffcodes[j] = huffnode[i].huffcodes[j];
        }
        huffnode[leftchild].huffcodes[fatherlength] = 0;
        huffnode[rightchild].huffcodes[fatherlength] = 1;
    }
    
    for (int i = 0; i < 256; i++) {
        encoding_huffmap->code_length[i] = huffnode[i].code_length;
        for (int j = 0; j < huffnode[i].code_length; j++) {
            encoding_huffmap->huffcodes[i][j] = huffnode[i].huffcodes[j];
        }
    }
}

int _writeFile(struct HUFFBMP *map, char *filename) {
    FILE *res = fopen(filename, "w");
    const char *hufname = "HUF";
    fwrite(map->bitmap->header, 1, HEADER_SIZE, res);
    fwrite(map->bitmap->info, 1, INFO_SIZE, res);
    if (map->bitmap->info->biOtherDataSize) {
        fwrite(map->bitmap->info->biOtherData, 1, map->bitmap->info->biOtherDataSize, res);
    }
    fwrite(map->bitmap->palette_ptr, 4, map->bitmap->palette_size, res);
    // write all auxillary data
    
    fwrite(hufname, 1, 3, res);
    // write 'huf as sign

    for (int i = 0; i < 256; i++) {
        fwrite(&map->code_length[i], 1, 1, res);
    }

    
    unsigned char *after = 0;
    unsigned int after_length = 0;
    unsigned char *out = (unsigned char *) calloc(256, 256);
    unsigned out_length = 0;

    for (int i = 0; i < 256; ++i) {
        after = map->huffcodes[i];
        after_length = map->code_length[i];
        _concatBinary(out, after, after_length, out_length);
        out_length += after_length;
    }
    fwrite(out, 1, out_length / 8 + 1, res);
    free(out);


    
    out = (unsigned char *) calloc(map->bitmap->raw_size, 1);
    out_length = 0;
    unsigned char before = 0;
    
    for (int i = 0; i < map->bitmap->raw_size; ++i) {
        before = map->bitmap->content_ptr[i];
        after = map->huffcodes[before];
        after_length = map->code_length[before];
        _concatBinary(out, after, after_length, out_length);
        out_length += after_length;
    }
    fwrite(out, 1, out_length / 8 + 1, res);
    printf("File size(after compression): %ld(0x%lx)\n", ftell(res), ftell(res));
    printf("compression efficiency:%%%.2lf\n", (1-((double)ftell(res)/map->bitmap->header->bfSize))*100);
    fclose(res);
    free(out);
    printf("Output filename:%s\n", filename);
    return 0;
}

void _startInput(char *filename) {
    fgets(filename, 20, stdin);
    int file_len = strlen(filename) - 1;
    filename[file_len] = '\0';
    if (file_len < 5 || filename[file_len - 4] != '.') {
        strcat(filename, ".bmp");
    }
}

void _concatBinary(unsigned char *dest, unsigned char *src, unsigned src_length, unsigned dest_length) {
    unsigned char *dest_base = dest + dest_length / 8;
    unsigned dest_offset = dest_length % 8;
    
    
    for (int i = 0; i < src_length; ++i) {
        _setBit(dest_base, src[i], dest_offset);
        dest_offset++;
        dest_base += dest_offset / 8;
        dest_offset %= 8;
    }
}

void _setBit(unsigned char *src, unsigned bit, unsigned pos) {
    pos = 7 - pos;
    if (bit) {
        *src = *src | (1 << pos);
    } else {
        *src = *src & ~(1 << pos);
    }
}

void _bitmapDestroy(Bitmap *map) {
    if (map->info->biOtherDataSize) {
        free(map->info->biOtherData);
    }
    
    free(map->header);
    free(map->content_ptr);
    free(map->info);
    free(map->palette_ptr);
    
    free(map);
}

void _huffmapDestroy(Huffmap *map) {
    _bitmapDestroy(map->bitmap);
    free(map);
    printf("-------------------END-------------------\n");
    printf("Press \"ENTER\" to continue...");
}