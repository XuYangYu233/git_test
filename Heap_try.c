#include <stdio.h>
#include <stdlib.h>
#define Max_N 10000

typedef struct {
    int datas[Max_N];
    int Heap_size;
} Heap;

//插入操作
void push(Heap *heap, int x)
{
    int indx = ++(heap->Heap_size); //首先插入到最后一个位置
    //向上调整
    while (indx > 1) //只有i>1才会有父节点
    {
        int parent_indx = indx / 2; //父节点编号
        if (heap->datas[parent_indx] <= x) //没有上下颠倒就结束调整
            break;
        heap->datas[indx] = heap->datas[parent_indx]; //大小颠倒就将当前节点上调
        indx = parent_indx;
    }
    heap->datas[indx] = x;
}

//删除操作
int pop(Heap *heap)
{
    int result = heap->datas[0]; //获取最值
    int x = heap->datas[--heap->Heap_size]; //相当于将最后的一个元素放到根节点
    int index = 1;
    while (2 * index <= heap->Heap_size) //一定要有子节点
    {
        int L_son_index = 2 * index;
        int R_son_index = 2 * index + 1;
        //比较儿子节点的最值
        int Min_index = L_son_index;
        if (R_son_index <= heap->Heap_size && heap->datas[R_son_index] < heap->datas[Min_index])
            Min_index = R_son_index;
        //如果没有上下颠倒就结束
        if (heap->datas[Min_index] >= x)
            break;
        //上下颠倒就交换
        heap->datas[index] = heap->datas[Min_index];
        index = Min_index;
    }
    heap->datas[index] = x;
    return result;
}

void Build_Heap(Heap **heap, int data[], int n)
{
    //创建一个空堆
    *heap = (Heap *)malloc(sizeof(Heap));
    (*heap)->Heap_size = 0;
    for (int i = 0; i < n; i++) //逐个插入元素
        push(*heap, data[i]);
}

int main()
{
    Heap *heap;
    int arr[]={5,8,6,2,4,9,7,3,1};
    int n=9, i, j;
    Build_Heap(&heap, arr, n);
    i = pop(heap);
    j = pop(heap);

    return 0;
}