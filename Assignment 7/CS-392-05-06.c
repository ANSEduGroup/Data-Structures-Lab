 #include<stdio.h>
 #include<stdlib.h>

 struct node
 {
     int coef;
     int pow;
     struct node *next;
 };
 typedef struct node p;
 p *start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL;

 p *create(p *start);
 void traverse(p *ptr);
 p *insert(p *start,int co,int exp);
 void add(p *p1,p *p2);
 void multi(p *p1,p *p2);

p *create(p *start)
{
    int n,i,c,e;
    p *new,*t;
    printf("Enter no of nodes to be inserted\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        new=(p*)malloc(sizeof(p));
        printf("Enter the coefficient\n");
        scanf("%d",&c);
        printf("Enter the exponent\n");
        scanf("%d",&e);
        new->coef=c;
        new->pow=e;
        new->next=NULL;
        if(start==NULL)
            start=new;
        else{
            t=start;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=new;
        }
    }
    return start;
}

void traverse(p *ptr)
{
    if(ptr==NULL)
        printf("Polynomial not created\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d^%d",ptr->coef,ptr->pow);
            ptr=ptr->next;

        if(ptr!=NULL)
            printf("+");
        else
            printf("\n");
        }
    }
}

p *insert(p *start,int coef,int pow)
{
    p *new,*t;
    new=(p*)malloc(sizeof(p));
    new->coef=coef;
    new->pow=pow;
    if(start==NULL)
        start=new;
    else{
        t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=new;
    }
    return start;
}

void add(p *p1,p *p2)
{
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->pow>p2->pow)
        {
            start3=insert(start3,p1->coef,p1->pow);
            p1=p1->next;
        }
        else if(p2->pow>p1->pow)
        {
            start3=insert(start3,p1->coef,p2->pow);
            p2=p2->next;
        }
        else
        {
            start3=insert(start3,p1->coef+p2->coef,p1->pow);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1!=NULL)
        {
            start3=insert(start3,p1->coef,p1->pow);
            p1=p1->next;
          }
          while(p2!=NULL)
          {
              start3=insert(start3,p2->coef,p2->pow);
              p2=p2->next;
          }
          traverse(start3);
}

void multi(p *p1,p *p2)
{
    p *temp;
    if(p1==NULL || p2==NULL)
        printf("Zero polynomial\n");
    else
    {
        while(p1!=NULL)
        {
            temp=p2;
            while(temp!=NULL)
            {
                start4=insert(start4,p1->coef*temp->coef,p1->pow+temp->pow);
                temp=temp->next;
            }
            p1=p1->next;
        }
    }
    traverse(start4);
}

int main()
{
    printf("First polynomial\n");
    start1=create(start1);
    traverse(start1);
    printf("Seconed polynomial\n");
    start2=create(start2);
    traverse(start2);
    printf("Addition result:");
    traverse(start1);
    printf(" + ");
    traverse(start2);
    add(start1,start2);
    printf("Multiply result:");
    traverse(start1);
    printf(" * ");
    traverse(start2);
    multi(start1,start2);
    return 0;
}
