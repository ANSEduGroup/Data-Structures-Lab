#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *lch;
 struct node *rch;
};
typedef struct node t;
t *tree=NULL;
t *insert(t *tree,int val)
{
 t *new;
 new=(t *)malloc(sizeof(t));
 new->data=val;
 new->lch=NULL;
 new->rch=NULL;
 if(tree==NULL)
 {
  tree=new;
 }
 else
 {
  t *parent=NULL,*ptr=tree;
  while(ptr!=NULL)
  {
   parent=ptr;
   if(val<ptr->data)
   {
    ptr=ptr->lch;
   }
   else
   {
    ptr=ptr->rch;
   }
  }
  if(val<parent->data)
  {
   parent->lch=new;
  }
  else
  {
   parent->rch=new;
  }
 }
 return tree;
}
void inorder(t *tree)
{
 t *temp;
 temp=tree;
 if(temp!=NULL)
 {
  inorder(temp->lch);
  printf(" %d",temp->data);
  inorder(temp->rch);
 }
}
void preorder(t *tree)
{
 t *temp;
 temp=tree;
 if(temp!=NULL)
 {
  printf(" %d",temp->data);
  preorder(temp->lch);
  preorder(temp->rch);
 }
}
void postorder(t *tree)
{
 t *temp;
 temp=tree;
 if(temp!=NULL)
 {
  postorder(temp->lch);
  postorder(temp->rch);
  printf(" %d",temp->data);
 }
}
void main()
{
 int n,val,i;
 printf("\n Enter no of element: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("\n Enter item:- ");
  scanf("%d",&val);
  tree=insert(tree,val);
 }
 printf("\n Inorder:- \n");
 inorder(tree);
 printf("\n Preorder:- \n");
 preorder(tree);
 printf("\n Postorder:- \n");
 postorder(tree);
}
