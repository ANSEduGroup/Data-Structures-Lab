#include<stdio.h>
#define max 10
int push(int);
int pop();
void dispaly();
int top=-1,item,stack[max];

int main()
{
    int ch;
    while(1)
    {
        printf("Enter 1.PUSH 2.POP\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter item\n");
                   scanf("%d",&item);
                   push(item);
                   break;
            case 2:pop();
                   break;
            default:printf("WRONG CHOICE\n");
                    break;
        }
    }
}

int push(int item)
{

    if(top==max-1)
    {
        printf("STACK FULL\n");
        return;
    }
    else
    {
        top=top+1;
        stack[top]=item;
    }
    dispaly();
    return;

}

int pop()
{

    if(top==-1)
     {
         printf("STACK EMPTY\n");
         return;
     }
     else
     {
         item=stack[top];
         top=top-1;
         printf("POP ITEM IS:%d\n",item);
     }
     return;
}

void dispaly()
{
    int i;
    if(top==-1)
        printf("STACK EMPTY\n");
    else
    {
        printf("\nTHE STACK IS:\n");
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
