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
void del_beg();
void del_end();
void insert_pos();
void del_pos();
void rev();
void traverse();

int main()
{
    int n;
    do
    {
    printf("Enter your choice\n1.insert_beg\n2.insrt_end\n3.del_beg\n4.del_end\n5.insert_pos\n6.del_pos\n7.reverse\n8.EXIT\n");
    scanf("%d",&n);
        switch(n)
        {
            case 1:insert_beg();
                break;
            case 2:insert_end();
                break;
            case 3:del_beg();
                break;
            case 4:del_end();
                break;
            case 5:insert_pos();
                break;
            case 6:del_pos();
                break;
            case 7:rev();
                break;
            case 8:exit(0);
                break;
            default:printf("ERROR");
                    break;
        }
    }while(n!=9);
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
void del_beg()
{
    NODE *temp;
    temp=start;
    if(start==NULL)
        printf("EMPTY");
    else if(start->next==NULL)
    {
        printf("Deleted item is %d\n",start->data);
        start=NULL;
    }
    else{
        printf("Deleted item is %d\n",temp->data);
        start=start->next;
        free(temp);
    }
    traverse();



}

void del_end()
{
    NODE *p,*loc;
    if(start==NULL)
        printf("EMPTY");
    else if(start->next==NULL)
    {
        printf("Deleted item is %d\n",start->data);
        start=NULL;
    }
    else{
        loc=start;
        while(loc->next!=NULL)
        {
            p=loc;
            loc=loc->next;
        }
        printf("Deleted item is %d\n",loc->data);
        p->next=NULL;
        free(loc);
    }
    traverse();
}

void insert_pos()
{
    int pos,item,count=1;
    printf("Enter position to be inserted\n");
    scanf("%d",&pos);
    printf("Enter the element\n");
    scanf("%d",&item);
    NODE *n,*temp,*ptemp;
    n->data=item;
    n->next=NULL;
    if(pos==1)
    {
        n->next=start;
        start=n;
    }
    else{
        count=1;
        temp=start;
    }
    while(count!=pos)
    {
        ptemp=temp;
        temp=temp->next;
        count++;
    }
    ptemp->next=n;
    n->next=temp;
    traverse();

}

void del_pos()
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
    else
    {
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
    traverse();
}

void rev()
{
    NODE *p=NULL,*post,*c;
    c=start;
    while(c!=NULL)
    {
        post=c->next;
        c->next=p;
        p=c;
        c=post;
    }
    start=p;
    traverse();
}
