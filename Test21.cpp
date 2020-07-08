#include <stdio.h>
#include <stdlib.h>
// ����ԭȡ��debug13��8.c,������������޸�
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* circle_create(int n);
int count_off(Node* head, int n, int k, int m);

int main()
{
    freopen("test21.txt", "r", stdin);
    int n, k, m = 7, t, i;
    char names[10005][25];
    scanf("%d %d %d", &n, &k, &t);
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    Node* head = circle_create(n);
    i = count_off(head, n, k, t);
    printf("%s", names[i - 1]);
    return 0;
}

Node* circle_create(int n)
{
    Node *temp, *new_node, *head;
    int i;

    // ������һ������ڵ㲢������
    temp = (Node*)malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    // ������ 2 ���� n ������ڵ㲢������
    for (i = 2; i <= n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    // ���һ���ڵ�ָ��ͷ������ѭ������
    temp->next = head;

    return head;
}

int count_off(Node* head, int n, int k, int t)
{
    int i;
    int res;
    int count;
    int m = 7;
    int first_flag = 1;
    Node* pre;
    Node* temp;
    Node* out;
    pre = head;
    count = 0;
    if (k == 1) {
        for (i = 1; i < n; i++) {
            pre = pre->next;
        }
    } else {
        for (i = 1; i < k - 1; i++) {
            pre = pre->next;
        }
    }
    temp = pre->next;
    i = t;
    while (1) {
        if (i % 10 == 7 || i % 7 == 0 || (i % 100) / 10 == 7 || (i % 1000) / 100 == 7) {
            if (temp->next == temp) {
                res = temp->data;
                break;
            }
            out = temp;
            temp = temp->next;
            pre->next = temp;
            free(out);
        } else {
            pre = temp;
            temp = temp->next;
        }
        i++;
    }

    return res;
}