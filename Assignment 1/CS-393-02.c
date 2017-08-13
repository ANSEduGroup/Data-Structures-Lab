#include<stdio.h>
int main()
{
    int item,i,j,temp,n,a[20],flag=0;
    printf("Enter the no. of elements\n");
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
                a[j]=[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("After sort\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("Array in reversed order:\n");
    for(i=n-1;i>=0;i--)
        printf("%d ",a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("Found at %d index",i);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Not Found");
}
