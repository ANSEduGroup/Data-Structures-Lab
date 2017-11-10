#include<stdio.h>
void linear_search(int a[20],int n,int item)
{
    int i,flag=0;

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

main()
{
    int n,item,i,a[20];
    printf("Enter no of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&item);
    linear_search(a,n,item);

}
