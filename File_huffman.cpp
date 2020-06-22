#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAXSIZE 256
#define elif else if
#define GCK system("PAUSE"); exit(0)
typedef struct{
    char cd[2*MAXSIZE];
    int start;
}HCode;

typedef struct{
    //char data;
    double weight;
    int parent;
    int lchild,rchild;
}HTNode;

int next_read=0,data_size=0,after_yasuo=0;

//创建哈夫曼树
void CreateHT(HTNode ht[], int n0){
    int i,k,lnode,rnode;
    double min1, min2;
    for(i=0;i<2*n0-1;i++){
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    for(i=n0;i<=2*n0-2;i++){
        min1 = min2 = 32767;
        lnode = rnode = -1;
        for(k=0;k<=i-1;k++){
            if(ht[k].parent == -1){
                if(ht[k].weight < min1){
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                }
                elif(ht[k].weight < min2){
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}

//由哈夫曼树创建哈夫曼编码
void CreateHCode(HTNode ht[], HCode hcd[], int n0){
    int i,f,c;
    HCode hc;
    cout << "正在构建哈夫曼编码:" << endl;
    for(i=0;i<n0;i++){
        hc.start = n0;
        c = i;
        f = ht[i].parent;
        hc.cd[hc.start+1] = 0;
        while(f!=-1){
            if(ht[f].lchild==c){
                hc.cd[hc.start--] = '0';
            }
            else{
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        for(int j=0;j<=2*MAXSIZE-hc.start;j++){
            hc.cd[j] = hc.cd[hc.start+j];       //将哈夫曼编码移动到了字符串开头，便于字符串拼接和打印的操作
        }
        hcd[i] = hc;
        cout << i << ":" << hcd[i].cd << endl;  //打印哈夫曼编码
    }
}

//文件读取函数，结果通过ht带出
void File_read(HTNode ht[], char filename[]){
    FILE *fi=NULL;
    char *ptr=NULL;
    char temp_ch;
    long long int check_len=0;
    fi = fopen(filename,"rb");
    if(fi==NULL){
        cout << "找不到文件!退出程序" << endl;
        GCK;
    }
    cout << "正在打开" << filename << endl;
    ptr = (char *)calloc(10, sizeof(char));
    if(ptr==NULL){
        cout << "内存申请失败0x001，退出程序" << endl;
        GCK;
    }
    fread(ptr, 10, 1, fi);
    if(ptr[0]!='B' && ptr[0]!='C'){
        LABLEA:
        cout << "该文件不是bmp格式！退出程序" << endl;
        GCK;
    }
    else{
        if(ptr[1]!='M'&&ptr[1]!='A'&&ptr[1]!='I'\
        &&ptr[1]!='P'&&ptr[1]!='C'&&ptr[1]!='T'){
            goto LABLEA;
        }
    }
    memcpy(&data_size,ptr+2,4);
    cout << "文件大小为" << data_size << "字节" << endl;
    fread(ptr, 4, 1, fi);
    memcpy(&next_read,ptr,4);
    free(ptr);
    cout << "正在跳转至" << next_read << "字节处" << endl;
    for(int i=14;i<next_read;i++){
        fgetc(fi);
    }
    int fuck=0;
    while(!feof(fi)){//cout << check_len << ":";
        //temp_ch = (char)fgetc(fi);
        fuck = fgetc(fi);
        check_len++;
        //ht[(int)temp_ch].weight++;      //统计
        ht[fuck].weight++;
        //cout << (int)temp_ch << endl;
    }    
    check_len--;
    if(check_len!=data_size-next_read){
        cout << "文件格式有误！退出程序" << endl;
        GCK;
    }
    cout << "文件读取完毕，数据段共有" << check_len << "字节" << endl;
    for(int i=0;i<MAXSIZE;i++){
        ht[i].weight /= check_len;      //将权重变为小数形式
    }

    fclose(fi);
}

//文件写入
void File_writein(HCode hcd[], char ori_filename[]){
    FILE *origin=NULL, *destination=NULL;
    char des_filename[]="";
    char ori_char,des_char;
    char *sum_str;

    origin = fopen(ori_filename, "rb");
    strcpy(des_filename, ori_filename);
    strcat(des_filename, ".huf");
    cout << "目标文件:" << des_filename << endl;
    destination = fopen(des_filename, "wb");
    for(int i=0;i<next_read;i++){   //文件头部区块原封不动地复制到目标文件中去
        ori_char = fgetc(origin);
        fputc(ori_char, destination);
        after_yasuo++;
    }
    cout << "文件头部区块传送完毕" << endl;
    sum_str = (char *)calloc(2, MAXSIZE);
    memset(sum_str, 0, 2*MAXSIZE*sizeof(char));
    while(!feof(origin)){
        int ort=0;
        ort = fgetc(origin);
        strcat(sum_str, hcd[ort].cd);
        while(sum_str[7]!=0){    //可以先把bmp文件都读出来，然后转换为哈夫曼编码后再一口气直接写入
            des_char = 0;        //不过那样会占用很多的空间，因此我采用的是这种边读边写的形式
            for(int i=0;i<8;i++){
                if(sum_str[i]=='0'){
                    des_char *= 2;
                }
                elif(sum_str[i]=='1'){
                    des_char *= 2;
                    des_char++;
                }
            }
            fputc(des_char, destination);
            after_yasuo++;
            for(int i=0;i<2*MAXSIZE-8;i++){
                sum_str[i] = sum_str[i+8];
            }
        }
    }
    if(sum_str[0]=='0' || sum_str[0]=='1'){
        des_char = 0;
        for(int i=0;i<8;i++){
            if(sum_str[i]=='0'){
                des_char *= 2;
            }
            elif(sum_str[i]=='1'){
                des_char *= 2;
                des_char++;
            }
        }
        fputc(des_char, destination);
        after_yasuo++;
    }
    cout << "数据域压缩完毕" << endl;

    free(sum_str);
    fclose(origin);
    fclose(destination);
}

int main(){
    HTNode ht[2*MAXSIZE];
    HCode hcd[MAXSIZE];
    int n0;
    char filename[MAXSIZE]="";
    cout << "请输入要压缩的文件名:";
    scanf("%s",filename);
    memset(ht, 0, sizeof(ht));
    File_read(ht, filename);
    n0 = 256;    
    CreateHT(ht, n0);
    cout << "哈夫曼树构建完成" << endl;
    CreateHCode(ht, hcd, n0);
    cout << "哈夫曼编码构建完成" << endl;

    File_writein(hcd, filename);
    cout << "文件压缩完成" << endl;
    cout << "压缩后文件大小为" << after_yasuo << "字节" << endl;
    cout << "压缩率为" << ((double)after_yasuo / data_size) * 100 << "%" << endl;

    return 0;
}