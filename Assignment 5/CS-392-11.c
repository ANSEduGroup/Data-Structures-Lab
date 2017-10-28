#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};typedef struct node nd;
nd *front=NULL,*rear=NULL;

void insert();
void del();
void traverse();


void main()
{
    int ch;
    do
    {
        printf("\n1.INSERT,\t2.DELETE");
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:del();
            break;
            default:printf("NOT ALLOW");
            break;
        }
    }while(ch!=3);
}

void insert()
{
    nd *new;
    int item;
    new=(nd *)malloc(sizeof(nd));
    printf("\nEnter the item:");
    scanf("%d",&item);
    new->data=item;
    new->next=NULL;
    if(front==NULL)
    {
        front=rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
    traverse();
}


void del()
{
    nd *temp;
    if(front==NULL)
    {
         printf("\nThe queue is empty");
    }
    else
    {
        temp=front;
        front=front->next;
        printf("The deleted item= %d\n",temp->data);
        temp->next=NULL;
        free(temp);
    }
    traverse();
}

void traverse()
{
    nd *p;
    if(front==NULL)
    {
        printf("\nThe Queue is empty");
    }
    else
    {
        p=front;
        printf("The Queue is:\n");
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}
