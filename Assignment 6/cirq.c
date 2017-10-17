#include<stdio.h>
#define max 5
int cir_insert(int);
int cir_del();
void display();
int q[max],item,rear=-1,front=-1,count;

main()
{
    int ch;
    while(1)
    {
        printf("Enter choice\n1.Circular insert\n2.Circular delete\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter item\n");
                    scanf("%d",&item);
                    cir_insert(item);
                    break;
            case 2:cir_del();
                    break;
            default:printf("ERROR");
                    break;
        }
    }
}

int cir_insert(int item)
{
    if(front==(rear+1)%max)
        printf("Queue full\n");
    else{
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            q[rear]=item;
        }

    else{
        rear=(rear+1)%max;
        q[rear]=item;
    }
    }
    display();
    return ;
}

int cir_del()
{
   if(front==-1)
    printf("Queue empty\n");
   else{
    if(front==rear)
    {
        printf("Deleted item :%d\n",q[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("Deleted item :%d\n",q[front]);
        front=(front+1)%max;
    }
   }
   display();
   return;
}

void display()
{
    int i;
    if(front==-1)
        printf("QUEUE EMPTY\n");
    else
    {
        printf("Queue is :\n");
        for(i=front;i!=rear;i=((i+1)%max))
        {
            printf("%d\n",q[i]);
        }
        printf("%d\n",q[i]);

    }
}
