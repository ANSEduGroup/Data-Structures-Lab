#include<stdio.h>
#include<stdlib.h>
void insert_beg();
void insert_end();
//void del_beg();
//void del_end();
void traverse();
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;
int main()
{
    int n;
    printf("Enter your choice 1.insert_beg 2.insrt_end 3.del_beg 4.del_end");
    scanf("%d",&n);
    do
    {
        switch(ch)
        {
            case 1:insert_beg();
                break;
            case 2:insert_end();
                break;
        }
    }while(n!=10);
    return 0;
}
void insert_beg()
{
    int item,c,i;
    NODE *p;
    printf("Enter no. of elements\n");
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        p=(NODE *)malloc(sizeof(NODE));
        printf("Emter item\n");
        scanf("%d",&item);
        p->data=item;
        p->next=NULL;
        if(start==NULL)
            start=p;
        else{
            p->next=start;
            start=p;
        }
    }
    traverse();
}

void traverse()
{

    NODE *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void insert_end()
{
    int c,i,item;
    NODE *p;
    NODE *loc;
    printf("Enter no. of elements to be inserted at the end\n");
    scanf("%d",&c);
     for(i=0;i<c;i++)
    {
        p=(NODE *)malloc(sizeof(NODE));
        printf("Emter item\n");
        scanf("%d",&item);
        p->data=item;
        p->next=NULL;
        if(start==NULL)
            start=p;
        else{
            loc=start;
            while(loc->next!=NULL)
            {
                loc=loc->next;
            }
            loc->next=p;

        }
    }
    traverse();
}
