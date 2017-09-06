#include <stdio.h>

void merging(int a[],int low, int mid, int high)
{
   int l1=low, l2=mid+1,b[10],i=low,k;

   while(l1 <= mid && l2 <= high)
    {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   i++;
   }

   while(l1 <= mid)
   {
      b[i] = a[l1];
      i++;l1++;
   }

   while(l2 <= high)
   {
      b[i] = a[l2];
      i++;l2++;
   }
   for(k=low;k<i;k++)
      a[k] = b[k];
}

void sort(int a[],int low, int high)
{
   int mid;
   if(low < high)
    {
      mid = (low + high) / 2;
      sort(a,low, mid);
      sort(a,mid+1, high);
      merging(a,low, mid, high);
    }
}

int main()
{
   int i,n,a[20];
   printf("Enter the no. of elements\n");
   scanf("%d",&n);
   printf("Enter the elements\n");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   sort(a,0,n-1);
   printf("\nList after sorting\n");
   for(i = 0; i <n; i++)
      printf("%d ", a[i]);
   return 0;
}
