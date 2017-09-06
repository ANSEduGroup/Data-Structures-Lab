#include<stdio.h>
void insert_sort(int a[],int n)
{
    int k=1,p,temp;
    while(k<=n)
    {
        temp=a[k];
        p=k-1;
        while(temp<a[p] && p>=0)
        {
            a[p+1]=a[p];
            p=p-1;
        }
        a[p+1]=temp;
        k++;
    }

}

int main()
{
    int n,i,a[20];
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
   insert_sort(a,n);
   printf("\nList after sorting\n");
   for(i=1;i<=n;i++)
      printf("%d ",a[i]);
   return 0;
}
