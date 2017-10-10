#include<stdio.h>
void search()
{
    int i,mid,low,a[20],n,up,item;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    printf("Enter elements in the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&item);
    low=0;
    up=n-1;
    while(low<=up)
    {
        mid=(low+up)/2;
        if(a[mid]>item)
        {
            up=mid-1;
        }
        else if(a[mid]<item)
        {
            low=mid+1;
        }
        else
        {
            printf("Found at index %d",mid);
            break;
        }
    }

}
int main()
{
    search();
    return 0;
}
