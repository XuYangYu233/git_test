/*
    
    开始界面：手动输入or播放现有
    输入简谱，用*代表数字上的点，用.代表数字下的点，音符之间用空格隔开，使用%s读取单个音符
    使用特定符号代表休止符
    每读取一个音符，就新建一个线程并播放该音符.mp3，sleep一定的时间后--一般是多少毫秒？需要查询--读取下一个音符
    每个线程播放一定时间后自动结束
*/
#include<thread>       
#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<mutex>
#include<time.h>


using namespace std;mutex mu;

#pragma comment(lib,"winmm.lib") //[1]

#define MAXLEN 127
#define XSTART 16
#define YSTART 5
#define LENOFPAGE 146
#define DEPTHOFPAGE 20
short piano_type=1;    //2表示亮音钢琴，1是原声钢琴

typedef union{
    int i;
    char c[10];
}CwithI;

typedef struct{
    char name[127];
    CwithI qusu;
    char ver[10];
}HEAD;

void play_sound(char keyboard_key);
void play_song(FILE *puzi,short *ystart,HEAD mus_info,short print_flag);
void decoding_func(char keyboard_key,char *sound_name,short piano_type);
void gotoxy(int x,int y);
void print_kuang();
void print_pkeys();
void cls_kuang(short,short);
HEAD readhead(FILE *);
void HideCursor();
void ShowCursor();
char begin_page();
char exit_page();
char manual_page();
char auto_page();
char setting_page();

int main(){
    short mode=0;
    while(1){   //所有页面的中转站
        if(mode==0){
            mode = begin_page();
        }
        if(mode==1){
            mode = manual_page();
        }
        if(mode==2){
            mode = auto_page();
        }
        if(mode==3){
            exit_page();
            break;
        }
        fflush(stdin);
    }
    return 0;
}

char exit_page(){
    HideCursor();
    char sentences[][127]={"PROGRAMME DESIGN","Xu_HongQaun from SCSE in WHU","MUSIC RESOURCE","autopiano.cn","SPECIAL THANKS TO",\
    "Professor Wang_ZhangYi","T.A. Ji_ZhaoXu","T.A. Ye_AoShuang","Information Department Dormitory 8-335",\
    "github.com/WarpPrism/AutoPiano","","Thank You for Playing My Game!"};/*最后一段字符串由于没有下一段字符串来清掉它，会滞留在屏幕上，因此用空字符串来做最后一个*/
    print_kuang();
    short ystart=YSTART+DEPTHOFPAGE/2-11,line=0,sigofstr=0;
    int speed=500;
    for(line=YSTART+DEPTHOFPAGE-2;line+(sizeof(sentences)/127-2)*2>YSTART/*+DEPTHOFPAGE/2-11*/;line--){
        for(sigofstr=0;sigofstr<sizeof(sentences)/127-1;sigofstr++){
            if(kbhit()){
                speed = 0;   //快速跳过制作人员名单
            }
            if((line+sigofstr*2)<=YSTART+DEPTHOFPAGE-3&&(line+sigofstr*2)>=YSTART+2){
                cls_kuang(line+sigofstr*2,-1);
                cls_kuang(line+sigofstr*2,1);   //上下两行都清除一下
                gotoxy(XSTART+LENOFPAGE/2-strlen(sentences[sigofstr])/2,line+sigofstr*2);
                cout << sentences[sigofstr];
            }
        }
        Sleep(speed);
    }
    for(line=YSTART+DEPTHOFPAGE-3;line>=YSTART+DEPTHOFPAGE/2-1;line--){
        cls_kuang(line,1);
        gotoxy(XSTART+LENOFPAGE/2-strlen(sentences[sizeof(sentences)/127-1])/2,line);
        cout << sentences[sizeof(sentences)/127-1];
        Sleep(speed);
    }
    gotoxy(XSTART+LENOFPAGE/2-strlen("请按任意键继续. . .")/2,YSTART+DEPTHOFPAGE-2);
    system("PAUSE");
    return 0;
}

char begin_page(){
    char line_one[]="Welcome to elec-piano!";
    char line_two[]="choose your mode:1.manual   2.auto   3.exit";
    print_kuang();
    gotoxy(XSTART+LENOFPAGE/2-strlen(line_one)/2,YSTART+DEPTHOFPAGE/2-3);   //将光标移到方框的正中央并打印文字
    cout << line_one;
    gotoxy(XSTART+LENOFPAGE/2-strlen(line_two)/2,YSTART+DEPTHOFPAGE/2-1);
    cout << line_two;
    gotoxy(XSTART+LENOFPAGE/2,YSTART+DEPTHOFPAGE/2+1);   //将光标移至中央
    char mode[127]={0};
    while(1){
        scanf("%s",mode);
        if(mode[0]>='1'&&mode[0]<='3'&&strlen(mode)==1){
            break;
        }
        else{
            gotoxy(XSTART+LENOFPAGE/2,YSTART+DEPTHOFPAGE/2+3);
            cout << "                                  ";
            gotoxy(XSTART+LENOFPAGE/2-strlen("Input error!please try again:")/2,YSTART+DEPTHOFPAGE/2+1);
            cout << "Input error!please try again:" << endl;
            gotoxy(XSTART+LENOFPAGE/2,YSTART+DEPTHOFPAGE/2+3);
        }
    }
    system("CLS");
    return (mode[0]-'0');
}

char auto_page(){
    FILE *dir,*puzi,*puzi_hx;
    char sys_dir_msg[127];
    char mus_namelist[50][127]={0};
    short numofsong=0,ystart=YSTART+1;
    //short sigofsong;
    HEAD mus_info,hx_info;
    print_kuang();
    gotoxy(XSTART+1,ystart);
    cout << "Choose your music:";
    gotoxy(XSTART+1,++ystart);
    dir = _popen("dir .\\piano","r");
    while(!feof(dir)){
        fscanf(dir,"%s",sys_dir_msg);
        if(strstr(sys_dir_msg,".dat")!=NULL){
            strcpy(mus_namelist[numofsong],sys_dir_msg);
            cout << ++numofsong << "." << sys_dir_msg;
            gotoxy(XSTART+1,++ystart);
        }
    }
    fclose(dir);
    //1.画钢琴键盘 finish
    //2.整这个字符数组 finish
    //2.5.将曲速与曲子捆绑，写在曲谱文件中  finish
    //3.音符雨?XXX不行？ unable
    //4.双音轨 
    //5.结尾处制作人员名单 finish
    //6.自动播放中途回到主页面 finish
    //7.整一个吉他的音乐包？
    CwithI tempci;
    while(1){
        scanf("%9s",tempci.c);///加一个输入检测 finsih
        tempci.c[9] = '\0';
        fflush(stdin);
        tempci.i = atoi(tempci.c);
        if(tempci.i==0||tempci.i>50||tempci.i<0){
            cls_kuang(ystart,1);
            cout << "Input Error!please try again:";
        }
        else{
            break;
        }
    }
    gotoxy(XSTART+1,++ystart);
    char path_mode[50]="piano\\%s";
    char path[50]={0};
    char path_hx[50]={0};
    sprintf(path,path_mode,mus_namelist[tempci.i-1]);
    strcpy(path_hx,path);
    path_hx[strlen(path)-1] = 'x';
    path_hx[strlen(path)-2] = 'h';
    puzi = fopen(path,"r");
    
    if(puzi==NULL){
        cout << "File does not exist! Check your input";
        Sleep(2500);
        system("cls");
        return 0;
    }
    short hx_flag=1;//这里为什么打不开path_hx时会直接报错？（而不是返回NULL）
    puzi_hx = fopen(path_hx,"r");
    if(puzi_hx==NULL){
        hx_flag = 0;
        //fclose(puzi_hx);
    }
    else{
        hx_info = readhead(puzi_hx);
    }
    mus_info = readhead(puzi);
    
    thread t(play_sound,'+');   //播放一段无声的MP3以加载播放器相关dll
    t.detach();
    system("cls");
    print_kuang();
    ystart=YSTART+1;
    gotoxy(XSTART+1,ystart);
    cout << "now play: " << mus_info.name;
    gotoxy(XSTART+1,++ystart);
    //两个音轨应该分开播放
    /*while(!(feof(puzi))){
        keyboard_key = fgetc(puzi);
        cout << keyboard_key;
        if(keyboard_key=='|'||keyboard_key=='\n'){
            if(keyboard_key=='\n'){
                if(ystart+1==DEPTHOFPAGE+YSTART-1){
                    ystart=YSTART+2;
                    cls_kuang(ystart,1);
                }
                else{
                    if(ystart+2==DEPTHOFPAGE+YSTART-1){
                        ystart++;
                        gotoxy(XSTART+1,ystart);
                    }
                    else{
                        ystart++;
                        cls_kuang(ystart,1);
                    }
                }
            }
            continue;
        }
        if(kbhit()){
            char kbout='\0';
            kbout = _getch();
            if(kbout=='\r'){
                system("cls");
                return 0;
            }
        }
        thread t(play_sound,keyboard_key);
        t.detach();
        Sleep(mus_info.qusu.i);
    }*/
    thread t_main(play_song,puzi,&ystart,mus_info,1);
    if(hx_flag==1){
        thread t_hx(play_song,puzi_hx,&ystart,hx_info,0);
        t_hx.join();
        fclose(puzi_hx);
    }
    t_main.join();
    fclose(puzi);
    gotoxy(XSTART+1,++ystart);
    cls_kuang(ystart,1);
    cout << "end" << endl;
    cls_kuang(++ystart,1);
    
    
    system("PAUSE");
    system("CLS");
    return 0;
}

char manual_page(){
    HideCursor();
    print_kuang();
    print_pkeys();
    gotoxy(XSTART+1,YSTART+DEPTHOFPAGE-2);
    cout << "press Enter to quit the manual mode!";
    //gotoxy(XSTART+LENOFPAGE/2,YSTART+DEPTHOFPAGE-2);
    thread t(play_sound,'+');   //播放一段无声的MP3以加载播放器相关dll
    t.detach();
    int i=0;
    while(1){
        char keyboard_key;
        keyboard_key = getch();
        if(keyboard_key=='\r'){
            break;     //按回车退出
        }
        thread t(play_sound,keyboard_key); //[2]
        t.detach();
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //[3]
    }
    gotoxy(XSTART+LENOFPAGE/2-strlen("exit")/2,YSTART+DEPTHOFPAGE/2);
    cout << "exit!";
    ShowCursor();
    system("CLS");
    return 0;
}

void decoding_func(char keyboard_key,char *sound_name,short piano_type){ //在plays函数中被引用，可有效降低创建线程时传参的复杂程度
    char jian[]={'1','!','2','@','3','4','$','5','%','6','^','7','8','*','9','(','0','q','Q',\
        'w','W','e','E','r','t','T','y','Y','u','i','I','o','O','p','P','a','s','S','d','D',\
        'f','g','G','h','H','j','J','k','l','L','z','Z','x','c','C','v','V','b','B','n','m'}; //所有音名对应的按键
    char zhi_zimu[][3]={"C","Cs","D","Ds","E","F","Fs","G","Gs","A","As","B"}; //音名字母部分
    char zhi_shuzi[][2]={"0","1","2","3","4","5","6","7"};  //音名数字部分
    
    for(short i=0;i<sizeof(jian);i++){
        if(keyboard_key==jian[i]){
            short zimu_bianhao=i%12;   //字母部分12个一轮回
            short shuzi_bianhao=i/12;    //数字部分每十二个音+1
            char ss_zimu[5],ss_shuzi[2];
            strcpy(ss_zimu,zhi_zimu[zimu_bianhao]);
            strcpy(ss_shuzi,zhi_shuzi[shuzi_bianhao+piano_type]);  //带一个piano_type补正可以拓展音域
            strcat(ss_zimu,ss_shuzi);
            strcpy(sound_name,ss_zimu);
        }
        else{
            continue;
        }
    }
}

void play_sound(char keyboard_key){  
    char sound_name[5]={0};    //音名
    char temp_command[MAXLEN]={0};     //mciSendString的命令
    if(keyboard_key=='+'){
        strcpy(sound_name,"No_sound");    //播放一段无声的声音，用于加载与播放器有关的DLL文件
    }
    else{
        decoding_func(keyboard_key,sound_name,piano_type);   //将键盘上的键对应地解码成音名
    }
    sprintf(temp_command,"open piano\\%s.mp3 alias %s",sound_name,sound_name);
    mciSendStringA(temp_command,0,0,0); //[4] //打开音名.mp3
    sprintf(temp_command,"play %s",sound_name);
    mciSendStringA(temp_command,0,0,0);    //播放
    Sleep(10000);
    sprintf(temp_command,"close %s",sound_name);   //关闭
    mciSendStringA(temp_command,0,0,0);
    return;
}

void play_song(FILE *puzi,short *ystart,HEAD mus_info,short print_flag){
    char keyboard_key;
    //time_t start_t, end_t;
    //double diff_t;
    while(!(feof(puzi))){
        thread t_sleep(Sleep,mus_info.qusu.i-mus_info.qusu.i/10);
        //time(&start_t);
        keyboard_key = fgetc(puzi);
        if(print_flag==1){
            cout << keyboard_key;
        }
        if(keyboard_key=='|'||keyboard_key=='\n'){
            if(keyboard_key=='\n'&&print_flag==1){
                if((*ystart)+1==DEPTHOFPAGE+YSTART-1){
                    *ystart=YSTART+2;
                    cls_kuang(*ystart,1);
                }
                else{
                    if((*ystart)+2==DEPTHOFPAGE+YSTART-1){
                        (*ystart)++;
                        gotoxy(XSTART+1,*ystart);
                    }
                    else{
                        (*ystart)++;
                        cls_kuang(*ystart,1);
                    }
                }
            }
            t_sleep.detach();
            continue;
        }
        if(kbhit()){
            char kbout='\0';
            kbout = _getch();
            if(kbout=='\r'){
                //fclose(puzi);
                t_sleep.detach();
                break;
            }
        }
        mu.lock();
        Sleep(10);
        mu.unlock();
        Sleep(10);
        mu.lock();
        mu.unlock();
        //time(&end_t);
        //diff_t = difftime(end_t, start_t);
        //cout << diff_t;
        t_sleep.join();
        thread t_sleep_s(Sleep,mus_info.qusu.i/10);
        thread t(play_sound,keyboard_key);
        t.detach();
        t_sleep_s.join();
        //Sleep(mus_info.qusu.i);
    }
    return;
}

void gotoxy(int x,int y){    //[5]
    _COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);  //设置鼠标位置
}

void print_kuang(){
    short start_x=XSTART,start_y=YSTART;
    short page_x=LENOFPAGE,page_y=DEPTHOFPAGE;
    gotoxy(start_x,start_y);      //将鼠标移动到起始点
    for(short y=0;y<page_y;y++){
        if(y==0||y==page_y-1){
            gotoxy(start_x,start_y+y);
            for(short x=0;x<=page_x;x++){
                cout << "=";     //若为第一行或最后一行，则打印page_x个=
            }
        }
        else{
            gotoxy(start_x,start_y+y);
            cout << '|';
            gotoxy(start_x+page_x,start_y+y);
            cout << '|';      //每行开头和末尾打印|
        }
    }
}

void print_pkeys(){
    short ystart=YSTART+1;
    gotoxy(XSTART+1,ystart);
    cout << "_________________________________________________________________________________________________________________________________________________";
    for(short i=0;i<6;i++){
        gotoxy(XSTART+1,++ystart);
        cout << "|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |   |";
    }
    gotoxy(XSTART+1,++ystart);
    cout << "|  |!| |@|  |  |$| |%| |^|  |  |*| |(|  |  |Q| |W| |E|  |  |T| |Y|  |  |I| |O| |P|  |  |S| |D|  |  |G| |H| |J|  |  |L| |Z|  |  |C| |V| |B|  |   |";
    for(short i=0;i<2;i++){
        gotoxy(XSTART+1,++ystart);
        cout << "|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |   |";
    }
    gotoxy(XSTART+1,++ystart);
    cout << "|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |   |";
    for(short i=0;i<2;i++){
        gotoxy(XSTART+1,++ystart);
        cout << "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |";
    }
    gotoxy(XSTART+1,++ystart);
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | q | w | e | r | t | y | u | i | o | p | a | s | d | f | g | h | j | k | l | z | x | c | v | b | n | m |";
    gotoxy(XSTART+1,++ystart);
    cout << "| C2| D2| E2| F2| G2| A2| B2| C3| D3| E3| F3| G3| A3| B3| C4| D4| E4| F4| G4| A4| B4| C5| D5| E5| F5| G5| A5| B5| C6| D6| E6| F6| G6| A6| B6| C7|";
    gotoxy(XSTART+1,++ystart);
    cout << "|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|";
}

void cls_kuang(short line,short mode){    //清除框框内的文字，比system（“cls”）更快
    gotoxy(XSTART+1,line);
    for(short c=0;c<LENOFPAGE-1;c++){
        printf(" ");
    }
    gotoxy(XSTART+1,line+mode);
    for(short c=0;c<LENOFPAGE-1;c++){
        printf(" ");
    }
    gotoxy(XSTART+1,line);
}

void HideCursor(){  //[6]
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

void ShowCursor(){
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = TRUE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

HEAD readhead(FILE *puzi){
    char flag=0,keyboard_key,count=0;
    char tempstr[127]={0};
    HEAD temphead;
    while(!feof(puzi)){
        keyboard_key = fgetc(puzi);
        if(keyboard_key=='<'){
            flag++;      
            continue;
        }
        if(keyboard_key=='>'){
            count = 0;
            
            flag++;        //使得变量flag兼具计数和条件判断的功能
            if(flag==2){
                strcpy(temphead.name,tempstr);
            }
            if(flag==4){
                strcpy(temphead.qusu.c,tempstr);
                temphead.qusu.i = atoi(temphead.qusu.c);
            }
            if(flag==6){
                strcpy(temphead.ver,tempstr);
                keyboard_key = fgetc(puzi);   //将最后一个>后的换行符给吃掉
                break;
            }
            memset(tempstr,'\0',sizeof(tempstr));
        }
        if(flag%2==1){
            tempstr[count++] = keyboard_key;
        }
    }
    return temphead;
}