#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 128
typedef struct{
    int num;
    int posi_1, posi_2;
}Num;
typedef Num ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

void InitStack(SqStack *&s){
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroyStack(SqStack *&s){
    free(s);
}

bool StackEmpty(SqStack *s){
    return (s->top==-1);
}

bool Push(SqStack *&s, ElemType e){
    if(s->top==MAXSIZE-1){
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e){
    if(s->top==-1){
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}


//查找栈中有无与e的位置相同的元素。有则返回false,无则返回true
bool SearchStack(SqStack *s, ElemType e){
    if(StackEmpty(s)){
        return true;
    }
    for(int i=0;i<=s->top;i++){
        if(s->data[i].posi_1==e.posi_1 || s->data[i].posi_1==e.posi_2\
        || s->data[i].posi_2==e.posi_2 || s->data[i].posi_2==e.posi_1){
            return false;
        }
    }
    return true;
}

void Print_arr(int *arr, int n){
    cout << "数组为:";
    for(int i=0;i<2*n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Search(int *arr, int n){
    int i=0,j;
    Num temp;
    bool found=false;
    SqStack *st,*trans;
    InitStack(st);
    InitStack(trans);
    while(1){
        while(i<n){
            j=0;
            temp.num = i + 1;
            LABLE_CONTI:
            for(;j<n;j++){
                LABLE_A:
                found = false;
                temp.posi_1 = j;
                temp.posi_2 = j + i + 2;
                if(SearchStack(st, temp)){
                    Push(st, temp);  //栈内无位置相同的数，则进栈
                    found = true;
                    break;
                }
            }
            if(!found){
                found = false;
                if(StackEmpty(st)){
                    goto LABLE_EXIT;
                }
                Pop(st, temp);
                i = temp.num - 1;
                j = temp.posi_1;
                j++;
                goto LABLE_A; //退栈重复
            }
            i++;
        }
        while(!StackEmpty(st)){
            Pop(st, temp);
            arr[temp.posi_1] = arr[temp.posi_2] = temp.num;
            Push(trans, temp);
        }
        while(!StackEmpty(trans)){
            Pop(trans, temp);
            Push(st, temp);
        }
        int out=0;
        for(int k=0;k<2*n;k++){
            out = out ^ arr[k];     //检验是否有多余重复的
        }
        if(out != 0){ 
            goto LABLE_EXIT;
        }
        Print_arr(arr, n);
        Pop(st, temp);
        i = temp.num - 1;
        j = temp.posi_1;
        j++;
        goto LABLE_CONTI;
    }
    LABLE_EXIT:
    DestroyStack(trans);
    DestroyStack(st);
}

int main(){
    int n=0;
    int *arr=NULL;
    cout << "输入任意正整数n:";
    scanf("%d", &n);
    arr = (int *)calloc(1, 2 * n * sizeof(int));
    Search(arr, n);
    free(arr);

    return 0;
}