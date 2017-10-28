#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node n;
n *head=NULL;

void traverse()
{
    n *temp;
    temp=head;
    printf("Circular linklist:\n");
    while(temp->link!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("%d\t",temp->data);
}

void create()
{
    n *new,*temp;
    int item,c,i;
    printf("Enter no. of items\n");
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        new=(n *)malloc(sizeof(n));
        printf("Enter item\n");
        scanf("%d",&item);
        new->data=item;
        new->link=NULL;
    if(head==NULL)
    {
        head=new;
        new->link=head;
    }
    else
    {
        temp=head;
        while(temp->link!=head)
        {
            temp=temp->link;
        }
        temp->link=new;
        head=new;
    }
    }
    traverse();
}

main()
{
    create();
}
