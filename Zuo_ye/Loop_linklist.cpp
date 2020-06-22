#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct pil{
    char numb,iden;
    struct pil *next;
}PIL;

int main(){
    PIL *head,*end,*node;
    head = (PIL *)malloc(sizeof(PIL));
    end = head;
    for(int i=1;i<=13;i++){
        node = (PIL *)malloc(sizeof(PIL));
        char t=1;
        node->iden = i;
        node->numb = t;
        end->next = node;
        end = node;
    }
    end->next = head->next;
    PIL *s;
    s = head->next;
    char c=1,r=13;
    while(r>1){
        s->numb = c%3;
        c++;
        if(s->numb==2){
            cout << "No." <<(int)s->next->iden << " says 3 and out!" << endl;
            s->next = s->next->next;
            c = 1;
            r--;
        }
        s = s->next;
        //cout << c << "!!! " << endl;
    }
    cout << (int)s->iden << " is the last!" << endl;

    return 0;
}