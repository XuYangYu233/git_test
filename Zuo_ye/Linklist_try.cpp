#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Book{
    int a;
    struct Book *next;
}BOOK;

void addnode(BOOK **end,int a){
    BOOK *node=NULL;
    node = (BOOK *)malloc(sizeof(BOOK));
    node->a = a;
    (*end)->next = node;
    *end = node;
}

int main(){
    BOOK *head=NULL,*end;
    BOOK *book;
    head = (BOOK *)malloc(sizeof(BOOK));
    end = head;
    int i=0;
    while(1){
        int temp;
        cout << "input the " << 1+(i++) << "th num:";
        scanf("%d",&temp);
        if(temp==-1){
            cout << "Exit!" << endl;
            break;
        }
        addnode(&end,temp);//cout << end->a << endl;
    }
    end->next = head->next;
    BOOK *s;
    s = head->next;
    cout << "Numbers are:";
    for(int j=0;j<i-1;j++){
        cout << s->a << " ";
        s = s->next;
    }
    cout << endl << "end" << endl;

    return 0;
}