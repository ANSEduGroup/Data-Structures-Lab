#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;
void insert_beg();
void insert_end();
void delete(NODE *);

void traverse(NODE *);
int main()
{
    int n;
    do
    {
    printf("Enter your choice 1.insert_beg 2.insrt_end 3.delete 4.traverse\n");
    scanf("%d",&n);
        switch(n)
        {
            case 1:insert_beg();
                break;
            case 2:insert_end();
                break;
            case 3:delete(start);
                break;
            case 4:traverse(start);
                break;
        }
    }while(n!=5);
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
        printf("Enter item\n");
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

}

void traverse(NODE *start)
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

}
void delete(NODE *start)
{
    int pos,count=1;
    printf("Enter the position to be deleted\n");
    scanf("%d",&pos);
    NODE *temp,*ptemp;
    if(pos==1)
    {
        temp=start;
        start=start->next;
        free(temp);
    }
    else{
        temp=start;
    }
    while(count!=pos)
    {
        ptemp=temp;
        temp=temp->next;
        count++;
    }
    ptemp->next=temp->next;
    free(temp);

}
