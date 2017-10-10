#include <stdio.h>
#include <stdlib.h>
#define max 10
int q[max],front=-1 , rear=-1 , item;

void insertion()
{
        if(rear==max)
        printf("Queue full\n");
        else{
                front=0;
            rear=rear+1;
            q[rear]=item;
        }
        show();
}

void deletion()
{
   if(front==-1 || front>rear)
    printf("Queue underflow\n");
    else
    {
        printf("Deleted item is %d",q[front]);
        front=front+1;
    }

 }


void show()
{
    int i;
     printf("Queue:-\n");
     for(i=0;i<=rear;i++)
     printf("%d\n",q[i]);

 }



int main()
{
    int ch;
     while(1)
    {
        printf("\nEnter 1.Insertion 2.Deletion\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter item\n");
                   scanf("%d",&item);
                   insertion();
                   break;
            case 2:deletion();
                   break;
            default:printf("WRONG CHOICE\n");
                    break;
        }
    }
    }
