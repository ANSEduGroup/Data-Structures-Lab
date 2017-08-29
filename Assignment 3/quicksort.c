#include<stdio.h>
int quick_sort(int a[50],int,int);
int partition(int a[50],int,int,int);
int n,f,l;
int main()
{
    int a[50],i;
    printf("\n Enter no of elements: ");
    scanf("%d",&n);
    l=n-1;
    for(i=0;i<n;i++)
    {
        printf("\n Enter element at %d index : ",i);
        scanf("%d",&a[i]);
    }
    printf("\n before sorting :");
    printf("\n Array -> ");
    for(i=0;i<n;i++)
    {

            printf("\t %d",a[i]);
    }

    quick_sort(a,f,l);
    printf("\n after performing quick sort : ");
    printf("\n Array -> ");
    for(i=0;i<n;i++)
    {

        printf("\t %d",a[i]);
    }
    return 0;
  }

int quick_sort(int a[50],int f, int l)
{
    int pos=f;
    if(f>=l)
    {
        return;
    }
    partition(a,f,l,pos);
    quick_sort(a,f,pos-1);
    quick_sort(a,pos+1,l);
    return;
  }

int partition(int a[50],int f,int l,int pos)
{
    int i=f,j=l;
    int temp=0;
    while(1)
    {
        while(a[pos]<=a[j] && pos!=j)
        {
            j--;
        }
        if(pos==j)
        {
            return;
        }
        if(a[pos]>a[j])
        {
            temp=a[j];
            a[j]=a[pos];
            a[pos]=temp;
            pos=j;
        }
        while(a[pos]>=a[i] && pos!=i)
        {
            i++;
        }
        if(pos==i)
        {
            return;
        }
        if(a[pos]<a[i])
        {
            temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
            pos=i;
        }
    }
    return;
}

