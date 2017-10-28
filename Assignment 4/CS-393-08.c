#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *start=NULL;
int item;
int lpush(int);
int lpop();
void traverse();

int main()
{

    int ch;
     while(1)
    {
        printf("Enter 1.PUSH 2.POP\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:lpush(item);
                   break;
            case 2:lpop();
                   break;
            default:printf("WRONG CHOICE\n");
                    break;
        }
    }
}

int lpush(int item)
{
    NODE *p;int c,i;
    printf("Enter no. of elements\n");
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        p=(NODE *)malloc(sizeof(NODE));
        printf("Enter item\n");
        scanf("%d",&item);
        if(p==NULL)
            return;
        else
        {
            p->data=item;
            p->next=start;
            start=p;
        }
    }
traverse();
return;
}

int lpop()
{
    NODE *temp;
    if(start==NULL)
        printf("STACK IS EMPTY");
    else
    {
        item=start->data;
        temp=start;
        start=start->next;
        printf("POP ITEM IS %d\n",item);
        free(temp);
    }
    traverse();
    return;
}

void traverse()
{

    NODE *ptr;
    ptr=start;
    printf("THE STACK IS:\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

