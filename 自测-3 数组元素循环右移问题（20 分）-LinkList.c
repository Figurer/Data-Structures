#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;

NODE* CreateArray(int n);
NODE* MoveArray(NODE* pHead, int move);
void PrintArray(NODE*pHead);

int main()
{
    int n, move;
    scanf("%d %d", &n, &move);
    
    NODE* p = CreateArray(n);

    p = MoveArray(p, move);

    PrintArray(p);
    return 0;
}

NODE* CreateArray(int n)
{
    NODE *pt, *pHead, *pTail;

    //创建头结点
    pt = (NODE*)malloc(sizeof(NODE*));
    if (pt != NULL)
    {
        scanf("%d", &pt->data);
        pt->next = NULL;

        pHead = pt;
        pTail = pt;
    }
    else { return NULL; }

    //创建节点
    for (int i = 1; i < n; i++)
    {
        pt = (NODE*)malloc(sizeof(NODE*));
        if (pt != NULL)
        {
            scanf("%d", &pt->data);

            pTail->next = pt;
            pTail = pt;
        }
        else { return NULL; }
    }
    pt->next = NULL;
    return pHead;
}

NODE* MoveArray(NODE* pHead, int move)
{
    NODE* p = pHead;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = pHead;

    p = pHead;
    for (int i = 0; i < move-1; i++)
    {
        p = p->next;
    }
    pHead = p->next;
    p->next = NULL;
    
    return pHead;
}

void PrintArray(NODE*pHead)
{
    NODE* p = pHead;
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d", p->data);
}