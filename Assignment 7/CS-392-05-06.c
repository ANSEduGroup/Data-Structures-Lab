#include<stdio.h>
#include<stdlib.h>
struct node
{
 int co;
 int exp;
 struct node *next;
};
typedef struct node p;
p *start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL;
p *create(p *start)
{
 p *new,*temp;
 int n,i,c,e;
 printf("\n Enter no of terms:- ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  new=(p *)malloc(sizeof(p));
  printf("\n Enter coefficient:- ");
  scanf("%d",&c);
  printf("\n Enter exponent:- ");
  scanf("%d",&e);
  new->co=c;
  new->exp=e;
  new->next=NULL;
  if(start==NULL)
  {
   start=new;
  }
  else
  {
   temp=start;
   while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=new;
  }
 }
 return start;
}
void traverse(p *ptr)
{
 if(ptr==NULL)
 {
  printf("\n Polynomial is empty ");
 }
 else
 {
  printf("\n Polynomial is: \n");
  while(ptr!=NULL)
  {
   printf(" %dx^%d",ptr->co,ptr->exp);
   ptr=ptr->next;
   if(ptr!=NULL)
   {
    printf(" + ");
   }
   else
   {
    printf("\n");
   }
  }
 }
}
p *insert(p *start,int c,int e)
{
 p *new,*temp;
 new=(p *)malloc(sizeof(p));
 new->co=c;
 new->exp=e;
 new->next=NULL;
 if(start==NULL)
 {
  start=new;
 }
 else
 {
  temp=start;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
  temp->next=new;
 }
 return start;
}
void add(p *p1,p *p2)
{
 while(p1!=NULL && p2!=NULL)
 {
  if(p1->exp>p2->exp)
  {
   start3=insert(start3,p1->co,p1->exp);
   p1=p1->next;
  }
  else if(p2->exp>p1->exp)
  {
   start3=insert(start3,p2->co,p2->exp);
   p2=p2->next;
  }
  else
  {
   start3=insert(start3,p1->co+p2->co,p1->exp);
   p1=p1->next;
   p2=p2->next;
  }
 }
 while(p1!=NULL)
 {
  start3=insert(start3,p1->co,p1->exp);
  p1=p1->next;
 }
 while(p2!=NULL)
 {
  start3=insert(start3,p2->co,p2->exp);
  p2=p2->next;
 }
 printf("\n After addition:- ");
}
void multiply(p *p1,p *p2)
{
 if(p1==NULL || p2==NULL)
 {
  printf("\n Multiplication is not possible ");
 }
 while(p1!=NULL)
 {
  p *temp;
  temp=p2;
  while(temp!=NULL)
  {
   start4=insert(start4,p1->co*temp->co,p1->exp+temp->exp);
   temp=temp->next;
  }
  p1=p1->next;
 }
 printf("\n After Multiplication:- ");
}
void main()
{
 printf("\n Create 1st Polynomial: ");
 start1=create(start1);
 traverse(start1);
 printf("\n Create 2nd Polynomial: ");
 start2=create(start2);
 traverse(start2);
 add(start1,start2);
 traverse(start3);
 multiply(start1,start2);
 traverse(start4);
}
