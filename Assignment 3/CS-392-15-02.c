#include<stdio.h>
int smallest(int a[],int,int);
void selection(int a[],int);
int main()
{
    int a[50],i,n;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("After sorting\n ");
    selection(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int smallest(int a[50],int k,int n)
{
    int pos=k,small,i;
    small=a[pos];
    for(i=k+1;i<n;i++)
    {
        if(a[i]<small)
        {
            small=a[i];
            pos=i;
        }
    }
    return pos;
}

void selection(int a[50],int n)
{
    int loc,temp,k;
    for(k=0;k<n;k++)
    {
        loc=smallest(a,k,n);
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
}
