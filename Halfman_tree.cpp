#include <iostream>
#include <string.h>
using namespace std;

#define elif else if

typedef struct {
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
} HTNode;

void CreateHT(HTNode ht[], int n0)
{
    int i, k, lnode, rnode;
    double min1, min2;
    for (i = 0; i < 2 * n0 - 1; i++) {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    for (i = n0; i <= 2 * n0 - 2; i++) {
        min1 = min2 = 32767;
        lnode = rnode = -1;
        for (k = 0; k <= i - 1; k++) {
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}

int main()
{
    HTNode array[128];
    memset(array, 0, sizeof(array));
    array[0].data = array[0].weight = 2;
    array[1].data = array[1].weight = 3;
    array[2].data = array[2].weight = 4;
    array[3].data = array[3].weight = 7;
    array[4].data = array[4].weight = 8;
    array[5].data = array[5].weight = 9;
    CreateHT(array, 6);

    return 0;
}