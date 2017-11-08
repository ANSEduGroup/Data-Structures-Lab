#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
};
typedef struct node cl;
cl *head=NULL;
void traverse()
{
 cl *temp;
 temp=head;
 printf("\n Circular Linklist: ");
 while(temp->link!=head)
 {
  printf("\t %d",temp->data);
  temp=temp->link;
 }
 printf("\t %d\n",temp->data);
 }
void create()
{
 cl *new,*temp;
 int item,c,i;
 printf("\n Enter no of items you want to store in circular linklist: ");
 scanf("%d",&c);
 for(i=0;i<c;i++)
 {
  new=(cl *)malloc(sizeof(cl));
  printf("\n Enter item: ");
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
   new->link=head;
  }
 }
 traverse();
}
void ins_beg()
{
 cl *new,*temp;
 int item,c,i;
 printf("\n Enter the no of nodes you want to insert at begin in circular linklist: ");
 scanf("%d",&c);
 for(i=0;i<c;i++)
 {
  new=(cl *)malloc(sizeof(cl));
  printf("\n Enter item: ");
  scanf("%d",&item);
  new->data=item;
  new->link=NULL;
  new->link=head;
  temp=head;
  while(temp->link!=head)
  {
   temp=temp->link;
  }
  temp->link=new;
  head=new;
 }
 traverse();
}
void ins_end()
{
 cl *new,*temp;
 int item,c,i;
 printf("\n Enter no of nodes you want to insert at end in circular linklist: ");
 scanf("%d",&c);
 for(i=0;i<c;i++)
 {
  new=(cl *)malloc(sizeof(cl));
  printf("\n Enter item: ");
  scanf("%d",&item);
  new->data=item;
  new->link=NULL;
  temp=head;
  while(temp->link!=head)
  {
   temp=temp->link;
  }
  temp->link=new;
  new->link=head;
 }
 traverse();
}
void del_beg()
{
 cl *temp,*t;
 temp=head;
 while(temp->link!=head)
 {
  temp=temp->link;
 }
 temp->link=head->link;
 t=head;
 printf("\n Deleted item is: %d\n",t->data);
 head=head->link;
 free(t);
 traverse();
}
void del_end()
{
 cl *temp,*t;
 temp=head;
 while(temp->link->link!=head)
 {
  temp=temp->link;
 }
 t=temp->link;
 printf("\n Deleted item is: %d\n",t->data);
 temp->link=head;
 free(t);
 traverse();
}
void main()
{
 create();
 ins_beg();
 ins_end();
 del_beg();
 del_end();
}
