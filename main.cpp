//
//    main.c
// 
//   国家网络安全学院
//   2019302180119 
//  王祥国 2020/5/30

#include "bitmap.h"

int main() {
    printf("Welcome!This is a compressor for BMP file\n");
    printf("Filename:");
    char *filename = (char *)malloc(20 * sizeof(char));
    _startInput(filename);
    // input process

    Huffmap *test = initHuffmap(filename);
    test->huffmanEncode(test);
    test->writeFile(test, strcat(filename, ".huf"));
    test->huffmapDestroy(test);
    // open file and Huffman encode

    free(filename);
    getchar();
    return 0;
}
