#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MaxCol 10
typedef int ElemType;
typedef struct Node1
{
	ElemType data[MaxCol];
	struct Node1 *next;
}DList;
typedef struct Node2
{
	int Row,Col;
	DList *next;
}HList;
void CreateTable(HList*&h)
{
	int i,j;
	DList *r,*s;
	r=(DList*)malloc(sizeof(DList));
	h=(HList*)malloc(sizeof(HList));
	printf("���������������");
	scanf("%d%d",&h->Row,&h->Col);
	for(i=0;i<h->Row;i++)
	{
		printf("��%d�У�",i+1);
		s=(DList*)calloc(1,sizeof(DList));
		for(j=0;j<h->Col;j++)
			scanf("%d",&s->data[j]);
		if(h->next==NULL)
			h->next=s;
		else
			r->next=s;
		r=s; 
	}
	r->next=NULL;
	free(s);
	free(r);
}
void DestroyTable(HList *&h)
{
	DList*pre=h->next,*p=pre->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;p=p->next;
	}
	free(pre);
	free(h);
}
void DispTable(HList*h)
{
	int j;
	DList *p=h->next;
	while(p!=NULL)
	{
		for(j=0;j<h->Col;j++)
			printf("%4d",p->data[j]);
		printf("\n");
		p=p->next;
	}
}
void LinkTable(HList *h1,HList *h2,HList *&h)
{
	int i,j,k;
	DList*p=h1->next,*q,*s,*r;
	printf("�����ֶ��ǣ���һ������ţ��ڶ�������ţ�");
	scanf("%d%d",&i,&j);
	h=(HList*)malloc(sizeof(HList));
	r=(DList*)malloc(sizeof(DList));
	h->Row=0;
	h->Col=h1->Col+h2->Col;
	h->next=NULL;
	while(p!=NULL)
	{
		q=h2->next;
		while(q!=NULL)
		{
			if(p->data[i-1]==q->data[j-1])
			{
				s=(DList*)malloc(sizeof(DList));
				for(k=0;k<h1->Col;k++)
					s->data[k]=p->data[k];
				for(k=0;k<h2->Col;k++)
					s->data[h1->Col+k]=q->data[k];
				if(h->next==NULL)
					h->next=s;
				else
					r->next=s;
				r=s;
				h->Row++;
			}
			q=q->next;
		}
		p=p->next;
	} 
	r->next=NULL;
}
int main()
{
	HList *h1,*h2,*h;
	printf("��һ��\n");
	CreateTable(h1);
	printf("�����\n");
	CreateTable(h2);
	LinkTable(h1,h2,h);
	printf("���ӽ����\n");
	DispTable(h);
	DestroyTable(h1);
	DestroyTable(h2);
	DestroyTable(h);
	return 1; 
}