#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define CHANG 100
#define KUAN 35
#define NUM_OF_POINTS 70

typedef struct pi{
    short px;
    short py;
    bool color; //黑是0白是1
    bool shang;
    bool xia;
    bool zuo;
    bool you;
    bool zuoshang;
    bool zuoxia;
    bool youshang;
    bool youxia;
    short sum;
}POINT_T;

void gotoxy(int x,int y){    //[6]
    _COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);  //设置鼠标位置
}

void printkuang(){
    short kuan=0,chang=0;
    for(kuan;kuan<KUAN;kuan++){
        if(kuan==0||kuan==KUAN-1){
            gotoxy(0,kuan);
            for(chang;chang<CHANG;chang++){
                printf("#");
            }
            chang = 0;
        }
        else{
            gotoxy(0,kuan);
            printf("#");
            gotoxy(CHANG-1,kuan);
            printf("#");
        }
    }
    return;
}

POINT_T rand_generator(){
    POINT_T *temp=NULL,temping;
    temp = (POINT_T *)malloc(sizeof(POINT));
    memset(temp,0,sizeof(POINT));
    FILE *fi=NULL,*fi2=NULL;
    fi = _popen(".\\Yuanbao_try_py.py","r");
    fi2 = _popen(".\\Yuanbao_try_py.py","r");
    short rannuma=0,rannumb=0;
    fscanf(fi,"%d",&rannuma);
    fscanf(fi2,"%d",&rannumb);
	fclose(fi);
    fclose(fi2);
    time_t seed;
	srand(time(&seed));
    temp->px = (rannuma%(CHANG-2))+1;//CHANG/3;
    temp->py = (rannumb%(KUAN-2))+1;//KUAN/3;
    temp->color = 1;
    temping = *temp;
    free(temp);
    return temping;
}

/*void detacter(POINT *pa,POINT *pb){
    if(pa->color)
    if(pa->px==(pb->px)+1){ //b在a左
        if(pa->py==(pb->py)+1){ //b在a下
            pa->zuoxia = 1;
            pb->youshang = 1;
        }
        if(pa->py==(pb->py)-1){ //b在a上
            pa->zuoshang = 1;
            pb->youxia = 1;
        }
        if(pa->py==pb->py){ //b,a水平
            pa->zuo = 1;
            pb->you = 1;
        }
    }
    if(pa->px==(pb->px)-1){ //b在a右
        if(pa->py==(pb->py)+1){ //b在a下
            pa->youxia = 1;
            pb->zuoshang = 1;
        }
        if(pa->py==(pb->py)-1){ //b在a上
            pa->youshang = 1;
            pb->zuoxia = 1;
        }
        if(pa->py==pb->py){ //b,a水平
            pa->you = 1;
            pb->zuo = 1;
        }
    }
    return;
}*/

void detecter_s(POINT_T set[CHANG-2][KUAN-2]){
    //for(short x=1;x<CHANG-3;x++){
    for(short x=CHANG-4;x>0;x--){
        //for(short y=1;y<KUAN-3;y++){
        for(short y=KUAN-4;y>0;y--){
            short xadd1=x+1,yadd1=y+1;
            short xjian1=x-1,yjian1=y-1;
            if(xjian1==0){
                xjian1 = CHANG-4;
            }
            if(xadd1==CHANG-3){
                xadd1 = 1;
            }
            if(yadd1==KUAN-3){
                yadd1 = 1;
            }
            if(yjian1==0){
                yjian1 = KUAN-4;
            }
            if(set[xjian1][yadd1].color==1){
                set[x][y].zuoxia = 1;
                set[x][y].sum++;
            }
            if(set[xjian1][y].color==1){
                set[x][y].zuo = 1;
                set[x][y].sum++;
            }
            if(set[xjian1][yjian1].color==1){
                set[x][y].zuoshang = 1;
                set[x][y].sum++;
            }
            if(set[xadd1][yadd1].color==1){
                set[x][y].youxia = 1;
                set[x][y].sum++;
            }
            if(set[xadd1][y].color==1){
                set[x][y].you = 1;
                set[x][y].sum++;
            }
            if(set[xadd1][yjian1].color==1){
                set[x][y].youshang = 1;
                set[x][y].sum++;
            }
            if(set[x][yadd1].color==1){
                set[x][y].xia = 1;
                set[x][y].sum++;
            }
            if(set[x][yjian1].color==1){
                set[x][y].shang = 1;
                set[x][y].sum++;
            }
            
        }
    }
}

void rule(POINT_T set[CHANG-2][KUAN-2]){
    for(short x=1;x<CHANG-3;x++){
        for(short y=1;y<KUAN-3;y++){
            //switch (set[x][y].shang+set[x][y].xia+set[x][y].youshang+set[x][y].you+set[x][y].youxia+set[x][y].zuo+set[x][y].zuoshang+set[x][y].zuoxia)
            switch (set[x][y].sum)
            {
            case 3:
                set[x][y].color = 1;
                gotoxy(x+1,y+1);
                printf("X");
                break;
            case 2:
                gotoxy(x+1,y+1);
                if(set[x][y].color==1) printf("X");
                else printf(" ");
                break;
            case 0:
            case 1:
                set[x][y].color = 0;
                gotoxy(x+1,y+1);
                printf(" ");
                break;
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                set[x][y].color = 0;
                gotoxy(x+1,y+1);
                printf(" ");
                break;
            default:
                break;
            }
            //Sleep(1);
        }
    }
    return;
}

void printset(POINT_T set[CHANG-2][KUAN-2]){
    for(short x=0;x<CHANG-2;x++){
        for(short y=0;y<KUAN-2;y++){
            if(set[x][y].color==1){
                gotoxy(x+1,y+1);
                printf("X");
            }
            if(set[x][y].color==0){
                gotoxy(x+1,y+1);
                printf(" ");
            }
            //Sleep(50);
        }
    }
}

int main(){
    printkuang(); //打印框
    POINT_T set[CHANG-2][KUAN-2];
    memset(set,0,sizeof(set));
    for(short i=0;i<NUM_OF_POINTS;i++){
        POINT_T temp;
        label:
        temp = rand_generator();
        /*for(short j=0;j<i;j++){
            if(i==0){
                break;
            }
            if(temp.px==set[j].px&&temp.py==set[j].py){
                goto label;
            }
        }*/
        set[temp.px-1][temp.py-1] = temp;
        gotoxy(temp.px,temp.py);
        printf("X");
        //Sleep(0);
    } //生成初始点
    int count=0;
    while(1){
        detecter_s(set);
        rule(set);
        //printset(set);
        gotoxy(CHANG+10,KUAN/2);
        printf("%d",count++);
        Sleep(25);
    }
    //system("PAUSE");
    return 0;
}