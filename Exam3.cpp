#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}LinkNode;

void Append(LinkNode *&head, int dest){
    LinkNode *node,*ptr;
    node = (LinkNode *)calloc(1, sizeof(LinkNode));
    node->data = dest;
    node->next = NULL;
    if(head==NULL){
        head = node;
    }
    else{
        ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

void Disp(LinkNode *head){
    LinkNode *ptr;
    ptr = head;
    while(ptr!=NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void DestroyList(LinkNode *&L){
    LinkNode *pre=L, *p=L->next;
    while(p!=NULL){
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

void InsertSort(LinkNode *&head){
	LinkNode *ptr,*last,*temp;
	ptr = head->next; 
	head->next = NULL;
	while(ptr != NULL){
		temp = ptr->next;
		last = head;
		while(last->next !=NULL && last->next->data < ptr->data) //�ҵ���p��Ľڵ� 
			last = last->next; 
		ptr->next = last->next;
		last->next = ptr;
		ptr = temp;
	} 
}

void MergeSort(LinkNode *&mlist, LinkNode *nlist, LinkNode *sum) {
    LinkNode *ptr = NULL;
    while(nlist!=NULL && sum!=NULL){
        LinkNode *front=NULL;
        front = (LinkNode *)calloc(1, sizeof(LinkNode));
        front->data = nlist->data < sum->data ? nlist->data : sum->data;
        front->next = NULL;
        if(mlist == NULL){
            mlist = front;
            ptr = mlist;
        }
        else{
            ptr->next = front;
            ptr = front;
        }
        if(nlist->data < sum->data){
            nlist = nlist->next;
        }
        else{
            sum = sum->next;
        }
    }
    while(nlist!=NULL){
        ptr->next = (LinkNode *)calloc(1, sizeof(LinkNode));
        ptr = ptr->next;
        ptr->next = NULL;
        ptr->data = nlist->data;
        nlist = nlist->next;
    }
    while(sum!=NULL){
        ptr->next = (LinkNode *)calloc(1, sizeof(LinkNode));
        ptr = ptr->next;
        ptr->next = NULL;
        ptr->data = sum->data;
        sum = sum->next;
    }
}

int main(){
    LinkNode *mlist=NULL, *nlist=NULL, *sum=NULL;
    int m, n, tmp;
    cout << "����m:";
    scanf("%d", &m);
    if(m <= 0){
        cout << "m�����Ϲ淶,�˳�" << endl;
        return 0;
    }
    cout << "����m������:";
    for(int i=0;i<m;i++){
        tmp = 0;
        scanf("%d", &tmp);
        Append(mlist, tmp);
    }
    InsertSort(mlist);
    cout << "���������:";
    Disp(mlist);
    cout << endl;

    cout << "����n:";
    scanf("%d", &n);
    if(n <= 0){
        cout << "n�����Ϲ淶,�˳�" << endl;
        return 0;
    }
    cout << "����n������:";
    for(int i=0;i<n;i++){
        tmp = 0;
        scanf("%d", &tmp);
        Append(nlist, tmp);
    }
    InsertSort(nlist);
    cout << "���������:";
    Disp(nlist);
    cout << endl;
    cout << "���й鲢����:";
    MergeSort(mlist, nlist, sum);
    Disp(sum);
    cout << endl;

    return 0;
}