#include <stdio.h>
#include <stdlib.h>
#define Max_N 10000

typedef struct {
    int datas[Max_N];
    int Heap_size;
} Heap;

//�������
void push(Heap *heap, int x)
{
    int indx = ++(heap->Heap_size); //���Ȳ��뵽���һ��λ��
    //���ϵ���
    while (indx > 1) //ֻ��i>1�Ż��и��ڵ�
    {
        int parent_indx = indx / 2; //���ڵ���
        if (heap->datas[parent_indx] <= x) //û�����µߵ��ͽ�������
            break;
        heap->datas[indx] = heap->datas[parent_indx]; //��С�ߵ��ͽ���ǰ�ڵ��ϵ�
        indx = parent_indx;
    }
    heap->datas[indx] = x;
}

//ɾ������
int pop(Heap *heap)
{
    int result = heap->datas[0]; //��ȡ��ֵ
    int x = heap->datas[--heap->Heap_size]; //�൱�ڽ�����һ��Ԫ�طŵ����ڵ�
    int index = 1;
    while (2 * index <= heap->Heap_size) //һ��Ҫ���ӽڵ�
    {
        int L_son_index = 2 * index;
        int R_son_index = 2 * index + 1;
        //�Ƚ϶��ӽڵ����ֵ
        int Min_index = L_son_index;
        if (R_son_index <= heap->Heap_size && heap->datas[R_son_index] < heap->datas[Min_index])
            Min_index = R_son_index;
        //���û�����µߵ��ͽ���
        if (heap->datas[Min_index] >= x)
            break;
        //���µߵ��ͽ���
        heap->datas[index] = heap->datas[Min_index];
        index = Min_index;
    }
    heap->datas[index] = x;
    return result;
}

void Build_Heap(Heap **heap, int data[], int n)
{
    //����һ���ն�
    *heap = (Heap *)malloc(sizeof(Heap));
    (*heap)->Heap_size = 0;
    for (int i = 0; i < n; i++) //�������Ԫ��
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