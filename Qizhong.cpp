#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXSIZE 128

typedef struct node{
    char name[MAXSIZE];
    struct node *next;
}Ticket;

/*typedef struct queue{
    char name[MAXSIZE];
    struct queue *next;
}Queue;*/

typedef struct{
    Ticket *font;
    Ticket *rear;
}Head_queue;

typedef struct{
    char destination[MAXSIZE];
    char sign;
    long time;
    int remain_tiks;
    Ticket *booked;
    Head_queue *wait;
}Hangban;

Hangban hb_sum[MAXSIZE];
int hb_ptr=-1;

void InitQueue(Head_queue *&q){
    q = (Head_queue *)malloc(sizeof(Head_queue));
    q->font = q->rear = NULL;
}

bool QueueEmpty(Head_queue *q){
    return (q->rear==NULL);
}

void enQueue(Head_queue *&q, char name[]){
    Ticket *p;
    p = (Ticket *)malloc(sizeof(Ticket));
    strcpy(p->name, name);
    p->next = NULL;
    if(q->rear==NULL){
        q->font = q->rear = p;
    }
    else{
        q->rear->next = p;
        q->rear = p;
    }
}

bool deQueue(Head_queue *&q, char name[]){
    Ticket *t;
    if(q->rear==NULL){
        return false;
    }
    t = q->font;
    if(q->font==q->rear){
        q->font = q->rear = NULL;
    }
    else{
        q->font = q->font->next;
    }
    strcpy(name, t->name);
    free(t);
    return true;
}

void Create_linklist(Ticket *&head){
    head = (Ticket *)calloc(1, sizeof(Ticket));
    head->next = NULL;
}

void Append_Node(Ticket *head, char name[]){
    Ticket *ptr=NULL, *node;
    node = (Ticket *)calloc(1, sizeof(Ticket));
    strcpy(node->name, name);
    ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = node;
    node->next =NULL;
}

bool Remove_Node(Ticket *head, char name[]){
    Ticket *ptr,*temp;
    ptr = head;
    while(ptr->next!=NULL){
        if(strstr(ptr->next->name,name) && !strcmp(ptr->next->name,name)){
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

int Len_Linklist(Ticket *head){
    Ticket *ptr;
    int i=0;
    ptr = head;
    while(ptr->next!=NULL){
        i++;
        ptr = ptr->next;
    }
    return i;
}

void Lu_ru(){
    hb_ptr++;
    cout << "请录入航班信息(用空格隔开)：终点，航班号（A、B单字符即可），日期(YYYYMMDD：20200421即可)、余票数量（总额5张即可）" << endl;
    scanf("%s %c %ld %d", hb_sum[hb_ptr].destination, &hb_sum[hb_ptr].sign, &hb_sum[hb_ptr].time, &hb_sum[hb_ptr].remain_tiks);
    Create_linklist(hb_sum[hb_ptr].booked);
    InitQueue(hb_sum[hb_ptr].wait);
}

bool Cha_xun(){
    int i=0;
    bool find_flag=false;
    char temp[MAXSIZE];
    memset(temp,'\0',MAXSIZE);
    strcpy(temp,hb_sum[0].destination);
    cout << "输入终点站名进行查询:" << endl;
    scanf("%s", temp);
    for(;i<=hb_ptr;i++){
        if(strstr(hb_sum[i].destination,temp)){
            find_flag = true;
            printf("航班号、时间、余票量如下:%c,%ld,%d\n",hb_sum[i].sign,hb_sum[i].time,hb_sum[i].remain_tiks);
            break;
        }
    }
    if(find_flag == false){
        cout << "未找到航班" << endl;
        return false;
    }
    return true;
}

void Ding_piao(){
    char name[MAXSIZE];
    char zhongdian[MAXSIZE];
    int i=0,j;
    bool zd_flag=false, name_flag=false;
    cout << "输入姓名、终点站（每个用户定一张票）(用空格隔开):" << endl;
    scanf("%s %s",name,zhongdian);
    for(;i<=hb_ptr;i++){ //检测终点存在
        if(strstr(hb_sum[i].destination,zhongdian)){
            zd_flag = true;
            break;
        }
    }
    for(j=0;j<=hb_ptr;j++){//    检测用户重名
        Ticket *ptr;
        ptr = hb_sum[j].booked;
        while(ptr!=NULL){
            if(strstr(ptr->name,name)){
                name_flag = true;
                break;
            }
            ptr = ptr->next;
        }
        if(name_flag==true){
            break;
        }
    }
    if(zd_flag==false){
        cout << "终点不存在" << endl;
        return;
    }
    if(name_flag==false){
        int tempnumb=0;
        tempnumb = Len_Linklist(hb_sum[i].booked);
        if(tempnumb<hb_sum[i].remain_tiks){
            Append_Node(hb_sum[i].booked,name);
            cout << "订票成功！" << endl;
        }
        else{
            enQueue(hb_sum[i].wait,name);
            cout << "该航班人数已满,现已加入排队" << endl;
        }
    }
    else{
        cout << "您已订票，不可再订" << endl;
    }
}

void Tui_piao(){
    char name[MAXSIZE];
    int j;
    bool name_flag=false;
    cout << "输入姓名，办理退票:" << endl;
    scanf("%s",name);
    for(j=0;j<=hb_ptr;j++){//    检测用户重名
        Ticket *ptr;
        ptr = hb_sum[j].booked;
        while(ptr!=NULL){
            if(strstr(ptr->name,name)){
                name_flag = true;
                break;
            }
            ptr = ptr->next;
        }
        if(name_flag==true){
            break;
        }
    }
    if(name_flag==false){
        cout << "未找到用户" << endl;
        return;
    }
    Remove_Node(hb_sum[j].booked,name);
    cout << "退票成功" << endl;
    if(!QueueEmpty(hb_sum[j].wait)){
        deQueue(hb_sum[j].wait,name);
        Append_Node(hb_sum[j].booked,name);
    }
}

void Cha_dui(){
    char name[MAXSIZE];
    cout << "输入姓名查询排队:" << endl;
    int j,k;
    bool queue_flag=false,dp_flag=false;
    scanf("%s",name);
    for(j=0;j<=hb_ptr;j++){//    检测用户重名
        Ticket *ptr;
        k=0;
        ptr = hb_sum[j].wait->font;
        while(ptr!=hb_sum[j].wait->rear){
            k++;
            if(strstr(ptr->name,name)){
                queue_flag = true;
                break;
            }
            ptr = ptr->next;
        }
        if(ptr!=NULL && strstr(ptr->name,name)){
            k++;
            queue_flag = true;
            break;
        }
        if(queue_flag==true){
            break;
        }
    }
    if(queue_flag==true){
        cout << "您现在排在第" << k << "位" << endl;
    }
    else{
        cout << "您已补票成功" << endl;
    }
}

int main(){
    char str1[MAXSIZE];
    while(1){
        cout << "1.录入 2.查询 3.订票 4.退票 5.查询队列 6.退出" << endl;
        scanf("%s",str1);
        switch(str1[0]){
            case '1':
                Lu_ru();
                break;
            case '2':
                Cha_xun();
                break;
            case '3':
                Ding_piao();
                break;
            case '4':
                Tui_piao();
                break;
            case '5':
                Cha_dui();
                break;
            case '6':
                return 0;
            default:
                cout << "输入有误！" << endl;
        }
        cout << endl;
    }
    return 0;
}