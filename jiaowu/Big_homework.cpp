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
char form_page(short yema);//<-函数式编程思想:每一页都是一个函数
char index_page();
void last_page();
char search_page(short yema);

int main(){
    char yema=-1; //用char类型存放127以内的数字，可以使占用内存变小
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
            //当前任务：1.完善我的课程功能
                            //a.给每个课程编号 完成
                            //b.通过编号搜索出课程并写入MINE.txt
                            //c.通过读取该txt文件获取我选中的课程，
                            //d.选课和撤课都通过操作txt来实现
                    //2.对表格实现动态选取长度，严防李芳（大）这样的错位事件发生 完成
                    //3.完善退出界面的UI 完成 
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
                        if(y==8) printf("%30s","欢迎使用武汉大学公选课数据库系统  ");
                        if(y==10) printf("%30s","您可以浏览或查询有关公选课的信息  ");
                        if(y==12) printf("%30s","请按下列指定的数字进入对应的界面  ");
                        if(y==14) printf("%30s","0.搜索  1.浏览  2.我的课程  3.退出");
                        x = PAGE_LEN/2+16;//思考主页面需要加入什么图案或元素//None
                    }
                    else cout << ' ';
                }
            }
        }
        cout << '\n';
    }
    cout << "选择模式:";
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
            cout << "输入有误,请重试:";
            continue;
        }
        yema = str2sho(temp);
        if(yema>=0&&yema<=3){
            if(yema==0){
                cout << "正在跳转至 搜索 页面. . ." << endl;
            }
            if(yema==1){
                cout << "正在跳转至 浏览 页面. . ." << endl;
            }
            if(yema==2){
                yema = 99;
                cout << "正在跳转至 我的课程 页面. . ." << endl;
            }
            if(yema==3){
                yema = 88;
                cout << "正在退出中. . ." << endl;
            }
            break;
        }
        else{
            cout << "输入有误,请重试:";
        }
    }
    PING;
    fflush(stdin);
    system("CLS");
    return (short)yema;
}

char search_page(short yema){
    cout << "您正在使用 搜索 页面!输入 88 以返回主页面" << endl;
    cout << "您可以输入关键字(课程名,授课教师,授课学院等)进行检索" << endl;
    cout << "注意:不建议您输入单个汉字或数字进行检索,以免发生编码错误!" << endl;
    cout << "请在冒号后输入关键字:";

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
        cout << "正在返回主页面. . . " << endl;
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
        cout << "\n未搜索到相关课程. . .\n" << endl;
    }
    else{
        if(count>=100){
            cout << "\n搜索结果过多，请进一步限制您的搜索范围. . .\n" << endl;
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
    cout << "请选择接下来的操作:0.继续搜索  1-24.进入相应浏览页面  88.返回主页面" << endl;
    scanf("%hd",&yema);
    if(yema==88) yema=-1;
    cout << "正在跳转中. . ." << endl;
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
        cout << "找不到该页面,请稍后重试..." << endl;
        yema = -1;
    }
    else{
        cout << "您正在使用 浏览 页面!输入 88 以返回主页面" << endl;
        for(short cou=0;cou<NUM_OF_LINE;cou++){
            arr[cou] = readline(fi);
            arr[cou].bianhao = (int)yema * 100 + cou + 1;
            if(feof(fi)!=0){
                break;
            }
        }
        printform(arr,NUM_OF_LINE);
        fclose(fi);
        cout << (short)yema << "/" << NUM_OF_PAGE << endl << "请输入页码:";
        yema = 88;
        char temp[3]="\0";//I don't kown why but it works
        while(1){
            scanf("%s",temp);
            yema = str2sho(temp);
            if(yema==88){
                cout << "正在跳转至主页面..." << endl;
                yema = -1;
                break;
            }
            if(yema>0&&yema<=NUM_OF_PAGE){
                cout << "正在跳转至第 " << (short)yema << " 页..." << endl;
                break;
            }
            else{
                cout << "页码输入有误，请重新输入:";
            }
        }
    }
    PING;//设置延时器来模拟网络延迟,优化用户使用体验
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
                            printf("%-20s","感谢您的使用,再见!");
                            x += 20;
                        }
                        if(y==10&&x==33){
                            printf("%-30s","程序设计:徐弘诠");
                            x += 30;
                        }
                        if(y==12&&x==33){
                            printf("%-40s","数据来源:武汉大学教务管理系统");
                            x += 40;
                        }
                        if(y==14&&x==33){
                            printf("%-40s","特别鸣谢:武汉大学国家网络安全学院");
                            x += 40;
                        }
                        if(y==16&&x==42){
                            printf("%-20s","王张宜 老师");
                            x += 20;
                        }
                        if(y==18&&x==42){
                            printf("%-20s","纪兆旭 助教老师");
                            x += 20;
                        }
                        if(y==20&&x==42){
                            printf("%-31s","武汉大学信息学部8舍335 ");
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
}//尾页可以写一下作者啊什么的，对，就是那个叫开发人员名单

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
        c = str[0] - '0';//<-19页为什么会段错误？
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
    templsn = (LESSON *)malloc(sizeof(LESSON));//这个地方要怎么释放内存？
    memset(templsn,'\0',sizeof(LESSON));
    fscanf(fi,"%s %s %s %s %s %s %s %s %s %s ",\
            templsn->lesson,templsn->score.fstr,templsn->teacher,templsn->place,\
            templsn->yuanxi,templsn->leibie,templsn->year.fstr,templsn->term.fstr,\
            templsn->shijiandidian,templsn->beizhu);
        templsn->score.fsho = str2flo(templsn->score.fstr);//<-这个地方是不是可以用共用体?
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

                //strcpy(geshi,signal_points);//直接使用signal_points会报错,为什么?可能是作用域的问题
                if(x==1){
                    for(unsigned short i=0;i<strlen(geshi);i++){
                        if(geshi[i]=='d'){
                            geshi[i] = 's';
                        }
                    }
                    printf(geshi,"编号","课程名称","学分","教师名","职称","授课学院",\
                    "领域","学年","学期","上课时间地点","备注");
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
}//是不是可以像上面那样排成一排？这样也方便了表格动态调整

void addnode(LINKLIST **end,LESSON lsn){
    LINKLIST *node=NULL;
    node = (LINKLIST *)malloc(sizeof(LINKLIST));
    node->lsn = lsn;
    (*end)->nxt = node;
    *end = node;
}
