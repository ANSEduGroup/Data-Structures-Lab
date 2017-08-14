#include<stdio.h>
void insert(int a[]);
void del(int a[]);
int n;
int main()
{
    int a[20],i,j,temp;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("After sort\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    insert(a);
    del(a);
    return 0;
}
void insert(int a[20])
{
    int p,i,k;
    printf("Enter the position\n");
    scanf("%d",&p);
    printf("Enter the element to be entered\n");
    scanf("%d",&k);
    i=n-1;
    while(i>=p)
    {
        a[i+1]=a[i];
        i--;
    }
    a[p]=k;
    n++;
    printf("After insertion:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
void del(int a[20])
{
    int i,p,k;
    printf("\n Enter the index to e deleted\n");
    scanf("%d",&p);
    i=p;
    k=a[p];
    while(i<n-1)
    {
        a[i]=a[i+1];
        i++;
    }
    n--;
    printf("After deletion\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
