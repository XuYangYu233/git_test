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

//������������
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

//�ɹ���������������������
void CreateHCode(HTNode ht[], HCode hcd[], int n0){
    int i,f,c;
    HCode hc;
    cout << "���ڹ�������������:" << endl;
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
            hc.cd[j] = hc.cd[hc.start+j];       //�������������ƶ������ַ�����ͷ�������ַ���ƴ�Ӻʹ�ӡ�Ĳ���
        }
        hcd[i] = hc;
        cout << i << ":" << hcd[i].cd << endl;  //��ӡ����������
    }
}

//�ļ���ȡ���������ͨ��ht����
void File_read(HTNode ht[], char filename[]){
    FILE *fi=NULL;
    char *ptr=NULL;
    char temp_ch;
    long long int check_len=0;
    fi = fopen(filename,"rb");
    if(fi==NULL){
        cout << "�Ҳ����ļ�!�˳�����" << endl;
        GCK;
    }
    cout << "���ڴ�" << filename << endl;
    ptr = (char *)calloc(10, sizeof(char));
    if(ptr==NULL){
        cout << "�ڴ�����ʧ��0x001���˳�����" << endl;
        GCK;
    }
    fread(ptr, 10, 1, fi);
    if(ptr[0]!='B' && ptr[0]!='C'){
        LABLEA:
        cout << "���ļ�����bmp��ʽ���˳�����" << endl;
        GCK;
    }
    else{
        if(ptr[1]!='M'&&ptr[1]!='A'&&ptr[1]!='I'\
        &&ptr[1]!='P'&&ptr[1]!='C'&&ptr[1]!='T'){
            goto LABLEA;
        }
    }
    memcpy(&data_size,ptr+2,4);
    cout << "�ļ���СΪ" << data_size << "�ֽ�" << endl;
    fread(ptr, 4, 1, fi);
    memcpy(&next_read,ptr,4);
    free(ptr);
    cout << "������ת��" << next_read << "�ֽڴ�" << endl;
    for(int i=14;i<next_read;i++){
        fgetc(fi);
    }
    int fuck=0;
    while(!feof(fi)){//cout << check_len << ":";
        //temp_ch = (char)fgetc(fi);
        fuck = fgetc(fi);
        check_len++;
        //ht[(int)temp_ch].weight++;      //ͳ��
        ht[fuck].weight++;
        //cout << (int)temp_ch << endl;
    }    
    check_len--;
    if(check_len!=data_size-next_read){
        cout << "�ļ���ʽ�����˳�����" << endl;
        GCK;
    }
    cout << "�ļ���ȡ��ϣ����ݶι���" << check_len << "�ֽ�" << endl;
    for(int i=0;i<MAXSIZE;i++){
        ht[i].weight /= check_len;      //��Ȩ�ر�ΪС����ʽ
    }

    fclose(fi);
}

//�ļ�д��
void File_writein(HCode hcd[], char ori_filename[]){
    FILE *origin=NULL, *destination=NULL;
    char des_filename[]="";
    char ori_char,des_char;
    char *sum_str;

    origin = fopen(ori_filename, "rb");
    strcpy(des_filename, ori_filename);
    strcat(des_filename, ".huf");
    cout << "Ŀ���ļ�:" << des_filename << endl;
    destination = fopen(des_filename, "wb");
    for(int i=0;i<next_read;i++){   //�ļ�ͷ������ԭ�ⲻ���ظ��Ƶ�Ŀ���ļ���ȥ
        ori_char = fgetc(origin);
        fputc(ori_char, destination);
        after_yasuo++;
    }
    cout << "�ļ�ͷ�����鴫�����" << endl;
    sum_str = (char *)calloc(2, MAXSIZE);
    memset(sum_str, 0, 2*MAXSIZE*sizeof(char));
    while(!feof(origin)){
        int ort=0;
        ort = fgetc(origin);
        strcat(sum_str, hcd[ort].cd);
        while(sum_str[7]!=0){    //�����Ȱ�bmp�ļ�����������Ȼ��ת��Ϊ�������������һ����ֱ��д��
            des_char = 0;        //����������ռ�úܶ�Ŀռ䣬����Ҳ��õ������ֱ߶���д����ʽ
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
    cout << "������ѹ�����" << endl;

    free(sum_str);
    fclose(origin);
    fclose(destination);
}

int main(){
    HTNode ht[2*MAXSIZE];
    HCode hcd[MAXSIZE];
    int n0;
    char filename[MAXSIZE]="";
    cout << "������Ҫѹ�����ļ���:";
    scanf("%s",filename);
    memset(ht, 0, sizeof(ht));
    File_read(ht, filename);
    n0 = 256;    
    CreateHT(ht, n0);
    cout << "���������������" << endl;
    CreateHCode(ht, hcd, n0);
    cout << "���������빹�����" << endl;

    File_writein(hcd, filename);
    cout << "�ļ�ѹ�����" << endl;
    cout << "ѹ�����ļ���СΪ" << after_yasuo << "�ֽ�" << endl;
    cout << "ѹ����Ϊ" << ((double)after_yasuo / data_size) * 100 << "%" << endl;

    return 0;
}