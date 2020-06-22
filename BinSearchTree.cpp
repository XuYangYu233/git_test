#include<iostream>

#define elif else if
typedef int KeyType;
typedef char InfoType;
typedef struct node{
    KeyType key;
    InfoType data;
    struct node *lchild,*rchild;
}BSTNode;

bool InsertBST(BSTNode *&bt, KeyType k){
    if(bt==NULL){
        bt = (BSTNode *)malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = NULL;
        return true;
    }
    elif(k==bt->key){
        return false;
    }
    elif(k<bt->key){
        return InsertBST(bt->lchild, k);
    }
    else{
        return InsertBST(bt->rchild, k);
    }
}

BSTNode* CreateBST(KeyType A[], int n){
    BSTNode *bt=NULL;
    int i=0;
    while(i<n){
        InsertBST(bt, A[i]);
        i++;
    }
    return bt;
}

BSTNode* SearchBST(BSTNode *bt, KeyType k){
    if(bt==NULL || bt->key==k){
        return bt;
    }
    if(k<bt->key){
        return SearchBST(bt->lchild, k);
    }
    else{
        return SearchBST(bt->rchild, k);
    }
}

//调用时f1设为NULL，f为找到节点的父节点
BSTNode* SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f){
    if(bt==NULL){
        f = NULL;
        return (NULL);
    }
    elif(k==bt->key){
        f = f1;
        return bt;
    }
    elif(k<bt->key){
        return SearchBST1(bt->lchild, k, bt, f);
    }
    else{
        return SearchBST1(bt->rchild, k, bt, f);
    }
}

void deletep(BSTNode *&p){
    BSTNode *q;
    q = p;
    p = p->rchild;
    free(q);
}

bool deletek(BSTNode *&bt, KeyType k){
    if(bt!=NULL){
        if(k==bt->key){
            deletep(bt);
            return true;
        }
        elif(k<bt->key){
            deletek(bt->lchild, k);
        }
        else{
            deletek(bt->rchild, k);
        }
    }
    else{
        return false;
    }
}