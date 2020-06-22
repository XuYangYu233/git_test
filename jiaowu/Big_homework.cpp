/*     +=======================================================+
       |              Lessons Inquiring System!                |
       |        You can use this to find some information      |
       |           about public choosing lessons in WHU        |
       |                      designed by                      |
       |              2019302180118 Xu_Hongquan                |
       +=======================================================+     */ 
//coding=gbk
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#include<cstdarg>
#define _CRT_SECURE_NO_WARNINGS
#define POINTS {0,5,27,32,39,50,64,83,88,93,130,147}
#define GESHI "|%04d|%-31s|%4d|%-06s|%-10s|%-13s|%-18s|%4d|%4d|%-36s|%-17s"
#define NUM_OF_LINE 15
#define NUM_OF_PAGE 25
#define PAGE_LEN 100
#define PAGE_WID 30
#define PING for(long long int c=0;c<1000000000;c++)
using namespace std;

typedef union{
    char fstr[5];
    short fsho;
}STR_W_SHO;

typedef struct{
    int bianhao;
    char lesson[50];
    STR_W_SHO score;
    char teacher[12];
    char place[30];
    char yuanxi[30];
    char leibie[20];
    STR_W_SHO year;
    STR_W_SHO term;
    char shijiandidian[50];
    char beizhu[35];
}LESSON;

typedef struct lian_biao{
    LESSON lsn;
    struct lian_biao *nxt;
}LINKLIST;

short linejudge(short y,int line,...);
float str2flo(char *str);
short str2sho(char *str);
void sho2str(char *str,short i);
void mkpath(char *str,short yema);
LESSON readline(FILE *fi);
void lenchange(int *len,char *dirstr,short point);
void geshichange(char *geshi,int *len,short lenpoint,short geshipoint);
void printform(LESSON *arr,int line);
void printline(LESSON arr,char *geshi);
void addnode(LINKLIST **end,LESSON lsn);
char form_page(short yema);//<-����ʽ���˼��:ÿһҳ����һ������
char index_page();
void last_page();
char search_page(short yema);

int main(){
    char yema=-1; //��char���ʹ��127���ڵ����֣�����ʹռ���ڴ��С
    while(1){
        if(yema==-1){
            yema = index_page();
        }
        if(yema>=1&&yema<=NUM_OF_PAGE){
            yema = form_page(yema);
        }
        if(yema==0){
            yema = search_page(yema);
        }
        if(yema==88){
            last_page();
            break;
        }
        if(yema==99){
            //��ǰ����1.�����ҵĿγ̹���
                            //a.��ÿ���γ̱�� ���
                            //b.ͨ������������γ̲�д��MINE.txt
                            //c.ͨ����ȡ��txt�ļ���ȡ��ѡ�еĿγ̣�
                            //d.ѡ�κͳ��ζ�ͨ������txt��ʵ��
                    //2.�Ա��ʵ�ֶ�̬ѡȡ���ȣ��Ϸ�����������Ĵ�λ�¼����� ���
                    //3.�����˳������UI ��� 
        }
    }
    system("PAUSE");
    return 0;
}

char index_page(){
    for(short y=1;y<=PAGE_WID;y++){
        for(short x=1;x<=PAGE_LEN;x++){
            if(y==1||y==PAGE_WID){
                if(x==1||x==PAGE_LEN) cout << '+';
                else cout << '-';
            }
            else{
                if(x==1||x==PAGE_LEN) cout << '|';
                else{
                    if(x==(PAGE_LEN/2-17)&&(y==PAGE_WID/3-2||y==PAGE_WID/3||\
                    y==PAGE_WID/3+2||y==PAGE_WID/3+4)){
                        if(y==8) printf("%30s","��ӭʹ���人��ѧ��ѡ�����ݿ�ϵͳ  ");
                        if(y==10) printf("%30s","������������ѯ�йع�ѡ�ε���Ϣ  ");
                        if(y==12) printf("%30s","�밴����ָ�������ֽ����Ӧ�Ľ���  ");
                        if(y==14) printf("%30s","0.����  1.���  2.�ҵĿγ�  3.�˳�");
                        x = PAGE_LEN/2+16;//˼����ҳ����Ҫ����ʲôͼ����Ԫ��//None
                    }
                    else cout << ' ';
                }
            }
        }
        cout << '\n';
    }
    cout << "ѡ��ģʽ:";
    char yema=1;
    while(1){
        yema = 1;    
        char temp[3]="\0";
        scanf("%s",temp);
        for(unsigned short c=0;c<strlen(temp);c++){
            if(temp[c]>='0'&&temp[c]<='9'){
                yema++;
            }
        }
        if(yema==1){
            cout << "��������,������:";
            continue;
        }
        yema = str2sho(temp);
        if(yema>=0&&yema<=3){
            if(yema==0){
                cout << "������ת�� ���� ҳ��. . ." << endl;
            }
            if(yema==1){
                cout << "������ת�� ��� ҳ��. . ." << endl;
            }
            if(yema==2){
                yema = 99;
                cout << "������ת�� �ҵĿγ� ҳ��. . ." << endl;
            }
            if(yema==3){
                yema = 88;
                cout << "�����˳���. . ." << endl;
            }
            break;
        }
        else{
            cout << "��������,������:";
        }
    }
    PING;
    fflush(stdin);
    system("CLS");
    return (short)yema;
}

char search_page(short yema){
    cout << "������ʹ�� ���� ҳ��!���� 88 �Է�����ҳ��" << endl;
    cout << "����������ؼ���(�γ���,�ڿν�ʦ,�ڿ�ѧԺ��)���м���" << endl;
    cout << "ע��:�����������뵥�����ֻ����ֽ��м���,���ⷢ���������!" << endl;
    cout << "����ð�ź�����ؼ���:";

    FILE *fi=NULL;
    char keyword[100];
    char count=0;
    char path[20]="\0";
    LINKLIST *head=NULL;
    LINKLIST *end;

    head = (LINKLIST *)malloc(sizeof(LINKLIST));
    end = head;

    scanf("%s",keyword);

    if(strcmp(keyword,"88")==0){
        cout << "���ڷ�����ҳ��. . . " << endl;
        PING;
        system("CLS");
        return -1;
    }

    for(short x=1;x<=NUM_OF_PAGE;x++){
        mkpath(path,x);
        fi = fopen(path,"r");
        for(short y=1;y<=NUM_OF_LINE;y++){
            LESSON *lsn;
            lsn = (LESSON *)malloc(sizeof(LESSON));
            memset(lsn,'\0',sizeof(LESSON));
            /*fscanf(fi,"%s %s %s %s %s %s %s %s %s %s ",\
                lsn->lesson,lsn->score.fstr,lsn->teacher,lsn->place,\
                lsn->yuanxi,lsn->leibie,lsn->year.fstr,lsn->term.fstr,\
                lsn->shijiandidian,lsn->beizhu);*/
            *lsn = readline(fi);
            if(strstr(lsn->lesson,keyword)!=NULL||strstr(lsn->teacher,keyword)!=NULL||\
            strstr(lsn->place,keyword)!=NULL||strstr(lsn->yuanxi,keyword)!=NULL||\
            strstr(lsn->leibie,keyword)!=NULL||strstr(lsn->shijiandidian,keyword)!=NULL){
                /*lsn->score.fsho = str2flo(lsn->score.fstr);
                lsn->year.fsho = str2sho(lsn->year.fstr);
                lsn->term.fsho = str2sho(lsn->term.fstr);*/
                lsn->bianhao = x * 100 + y;
                addnode(&end,*lsn);
                count++;
            }
            if(feof(fi)!=0){
                break;
            }
            free(lsn);
        }
        fclose(fi);
    }
    if(count==0){
        cout << "\nδ��������ؿγ�. . .\n" << endl;
    }
    else{
        if(count>=100){
            cout << "\n����������࣬���һ����������������Χ. . .\n" << endl;
        }
        else{
            end->nxt = NULL;
            LESSON arr[count];
            memset(arr,'\0',sizeof(arr));
            LINKLIST *p;
            p = head->nxt;
            for(short i=0;i<count;i++){
                arr[i] = p->lsn;
                p = p->nxt;
            }
            printform(arr,count);
        }
        LINKLIST *s,*temp;
        for(s=head;s!=NULL;s=temp){
            temp=s->nxt;
            free(s);
        }
    }
    cout << "��ѡ��������Ĳ���:0.��������  1-24.������Ӧ���ҳ��  88.������ҳ��" << endl;
    scanf("%hd",&yema);
    if(yema==88) yema=-1;
    cout << "������ת��. . ." << endl;
    PING;
    fflush(stdin);
    system("CLS");
    return yema;
}

char form_page(short yema){
    char path[20];
    FILE *fi=NULL;
    LESSON arr[NUM_OF_LINE];
    memset(arr,'\0',sizeof(arr));
    mkpath(path,yema);
    fi = fopen(path,"r");
    if(fi==NULL){
        cout << "�Ҳ�����ҳ��,���Ժ�����..." << endl;
        yema = -1;
    }
    else{
        cout << "������ʹ�� ��� ҳ��!���� 88 �Է�����ҳ��" << endl;
        for(short cou=0;cou<NUM_OF_LINE;cou++){
            arr[cou] = readline(fi);
            arr[cou].bianhao = (int)yema * 100 + cou + 1;
            if(feof(fi)!=0){
                break;
            }
        }
        printform(arr,NUM_OF_LINE);
        fclose(fi);
        cout << (short)yema << "/" << NUM_OF_PAGE << endl << "������ҳ��:";
        yema = 88;
        char temp[3]="\0";//I don't kown why but it works
        while(1){
            scanf("%s",temp);
            yema = str2sho(temp);
            if(yema==88){
                cout << "������ת����ҳ��..." << endl;
                yema = -1;
                break;
            }
            if(yema>0&&yema<=NUM_OF_PAGE){
                cout << "������ת���� " << (short)yema << " ҳ..." << endl;
                break;
            }
            else{
                cout << "ҳ��������������������:";
            }
        }
    }
    PING;//������ʱ����ģ�������ӳ�,�Ż��û�ʹ������
    fflush(stdin);
    system("CLS");
    return yema;
}

void last_page(){
    for(short y=1;y<=PAGE_WID;y++){
        for(short x=1;x<=PAGE_LEN;x++){
            if(y==1||y==PAGE_WID){
                if(x==1||x==PAGE_LEN){
                    cout << '+';
                }
                else{
                    cout << '-';
                }
            }
            else{
                if(x==1||x==PAGE_LEN){
                    cout << '|';
                }
                else{
                    if(linejudge(y,7,8,10,12,14,16,18,20)==1){
                        if(y==8&&x==33){
                            printf("%-20s","��л����ʹ��,�ټ�!");
                            x += 20;
                        }
                        if(y==10&&x==33){
                            printf("%-30s","�������:���ڹ");
                            x += 30;
                        }
                        if(y==12&&x==33){
                            printf("%-40s","������Դ:�人��ѧ�������ϵͳ");
                            x += 40;
                        }
                        if(y==14&&x==33){
                            printf("%-40s","�ر���л:�人��ѧ�������簲ȫѧԺ");
                            x += 40;
                        }
                        if(y==16&&x==42){
                            printf("%-20s","������ ��ʦ");
                            x += 20;
                        }
                        if(y==18&&x==42){
                            printf("%-20s","������ ������ʦ");
                            x += 20;
                        }
                        if(y==20&&x==42){
                            printf("%-31s","�人��ѧ��Ϣѧ��8��335 ");
                            x += 30;
                        }
                        else{
                            cout << ' ';
                        }
                    }
                    else{
                        cout << ' ';
                    }
                }
            }
        }
        cout << endl;
    }
}//βҳ����дһ�����߰�ʲô�ģ��ԣ������Ǹ��п�����Ա����

short linejudge(short y,int line,...){
    va_list valist;
    va_start(valist,line);
    for(short i=0;i<line;i++){
        if(y==va_arg(valist,int)){
            return 1;
        }
    }
    va_end(valist);
    return 0;
}

short str2sho(char str[]){
    int i=strlen(str);
    int sum=0;
    short count=0;
    for(int j=i-1;j>=0;j--){
        volatile int t,s=str[j]-'0';
        if(s<0||s>9) continue;
        t = s * (int)pow(10,count++);
        sum += t;
    }
    return (short)sum; 
}

float str2flo(char str[]){
    short c=0;
    if(str[0] != '\0'){
        c = str[0] - '0';//<-19ҳΪʲô��δ���
        return (float)c;
    }
    return 0;
}

void sho2str(char str[],short t){
    if(t>9){
        char a=t/10+'0';
        char b=t%10+'0';
        str[0] = a;
        str[1] = b;
        str[2] = '\0';
    }
    else{
        str[0] = t + '0';
        str[1] = '\0';
    }
}

void mkpath(char *str,short yema){
    /*char s[3];
    char path1[20]="jiaowu/jiaowu";
    char path2[20]=".txt";
    sho2str(s,yema);
    strcat(path1,s);
    strcat(path1,path2);
    strcpy(str,path1);*/
    sprintf(str,"jiaowu/jiaowu_two%hd.txt",yema);
}

LESSON readline(FILE *fi){
    LESSON *templsn;
    templsn = (LESSON *)malloc(sizeof(LESSON));//����ط�Ҫ��ô�ͷ��ڴ棿
    memset(templsn,'\0',sizeof(LESSON));
    fscanf(fi,"%s %s %s %s %s %s %s %s %s %s ",\
            templsn->lesson,templsn->score.fstr,templsn->teacher,templsn->place,\
            templsn->yuanxi,templsn->leibie,templsn->year.fstr,templsn->term.fstr,\
            templsn->shijiandidian,templsn->beizhu);
        templsn->score.fsho = str2flo(templsn->score.fstr);//<-����ط��ǲ��ǿ����ù�����?
        templsn->year.fsho = str2sho(templsn->year.fstr);
        templsn->term.fsho = str2sho(templsn->term.fstr);
    return *templsn;
    free(templsn);
}

void lenchange(int *len,char *dirstr,short point){
    short dirlen=strlen(dirstr);//cout << dirlen << endl;
    short dircha=dirlen - (len[point] - len[point-1] - 1);
    if(dircha>0){
        for(short j=point;j<12;j++){
            len[j] += dircha;
        }
    }
}

void geshichange(char *geshi,int *len,short lenpoint,short geshipoint){
    short tcrlen=len[lenpoint]-len[lenpoint-1]-1;
    char tcrlenstr[3];
    sho2str(tcrlenstr,tcrlen);//cout << tcrlen << endl;
    if(tcrlen>9){
        for(short shory=0;shory<2;shory++){
            geshi[geshipoint+shory] = tcrlenstr[shory];
        }
    }
    else{
        geshi[geshipoint+1] = tcrlenstr[0];
    }
}

void printform(LESSON arr[],int line){
    int len[]=POINTS;
    for(short i=0;i<line;i++){
        lenchange(len,arr[i].lesson,2);
        lenchange(len,arr[i].teacher,4);
        lenchange(len,arr[i].yuanxi,6);
        lenchange(len,arr[i].shijiandidian,10);
    }
    
    for(int x=0;x<(line*2)+3;x++){
        short mark[12]={0};
        for(short count=0;count<12;count++){
            mark[count] = len[count]; 
        }
        for(int y=0;y<len[11];y++){
            if(x%2==0){
                int mk=0;
                for(int i=0;i<11;i++){
                    if(y==mark[i]){
                        mk = 1;
                        mark[i] = -1;
                        break;
                    }
                }
                if(mk==1) cout<<"+";
                else cout<<"-";
            }
            else{
                char geshi[]=GESHI;
                geshichange(geshi,len,2,8);
                geshichange(geshi,len,4,18);
                geshichange(geshi,len,6,30);
                geshichange(geshi,len,10,50);

                //strcpy(geshi,signal_points);//ֱ��ʹ��signal_points�ᱨ��,Ϊʲô?�����������������
                if(x==1){
                    for(unsigned short i=0;i<strlen(geshi);i++){
                        if(geshi[i]=='d'){
                            geshi[i] = 's';
                        }
                    }
                    printf(geshi,"���","�γ�����","ѧ��","��ʦ��","ְ��","�ڿ�ѧԺ",\
                    "����","ѧ��","ѧ��","�Ͽ�ʱ��ص�","��ע");
                    break;
                }
                else{
                    printline(arr[(x-3)/2],geshi);
                    break;
                }
            }
        }
        printf("\n");
    }
}

void printline(LESSON arr,char *geshi){
    printf(geshi,arr.bianhao,arr.lesson,arr.score.fsho,arr.teacher,\
    arr.place,arr.yuanxi,arr.leibie,arr.year.fsho,arr.term.fsho,\
    arr.shijiandidian,arr.beizhu);
}//�ǲ��ǿ��������������ų�һ�ţ�����Ҳ�����˱��̬����

void addnode(LINKLIST **end,LESSON lsn){
    LINKLIST *node=NULL;
    node = (LINKLIST *)malloc(sizeof(LINKLIST));
    node->lsn = lsn;
    (*end)->nxt = node;
    *end = node;
}
