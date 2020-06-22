#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;

//头插法
void CreateListF(LinkNode *&L, ElemType a[], int n){
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for(int i=0;i<n;i++){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

//尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n){
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for(int i=0;i<n;i++){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void InitList(LinkNode *&L){
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
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

bool ListEmpty(LinkNode *L){
    return (L->next==NULL);
}

//求长度
int ListLength(LinkNode *L){
    int n=0;
    LinkNode *p=L;
    while(p->next!=NULL){
        n++;
        p = p->next;
    }
    return n;
}

void DispList(LinkNode *L){
    LinkNode *p=L->next;
    while(p!=NULL){
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

//求第i个节点的数据值
bool GetElem(LinkNode *L, int i, ElemType &e){
    int j=0;
    LinkNode *p=L;
    if(i<=0){
        return false;
    }
    while(j<i && p!=NULL){
        j++;
        p = p->next;
    }
    if(p==NULL){
        return false;
    }
    else{
        e = p->data;
        return true;
    }
}

//按元素值查找
int LocateElem(LinkNode *L, ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL && p->data!=e){
        p = p->next;
        i++;
    }
    if(p==NULL){
        return 0;
    }
    else{
        return i;
    }
}

bool ListInsert(LinkNode *&L, int i, ElemType e){
    int j=0;
    LinkNode *p=L, *s;
    if(i<=0){
        return false;
    }
    while(j<i-1 && p!=NULL){
        j++;
        p = p->next;
    }
    if(p==NULL){
        return false;
    }
    else{
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool ListDelete(LinkNode *&L, int i, ElemType &e){
    int j=0;
    LinkNode *p=L, *q;
    if(i<=0){
        return false;
    }
    while(j<i-1 && p!=NULL){
        j++;
        p = p->next;
    }
    if(p==NULL){
        return false;
    }
    else{
        q = p->next;
        if(q==NULL){
            return false;
        }
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}