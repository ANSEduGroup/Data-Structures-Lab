#include<stdio.h>
int quick(int a[],int,int);
int part(int a[],int,int,int);
int n,f,l,pos;
int main()
{
    int i,a[50];
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    l=n-1;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick(a,f,l);
    printf("After sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

int quick(int a[50],int f,int l)
{
    int pos=f;
    if(f>=l)
    {
        return 0;
    }
    part(a,f,l,pos);
    quick(a,f,pos-1);
    quick(a,pos+1,l);
    return 0;

}

int part(int a[50],int f,int l,int pos)
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
            return 0;
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
            return 0;
        }
        if(a[pos]<a[i])
        {
            temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
            pos=i;
        }
    }
    return 0;
}
