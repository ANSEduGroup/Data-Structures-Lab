#include<stdio.h>
#define max 10
void dfs(int a[][max],int visited[],int,int);

main()
{
    int i,j,a[max][max],n,visited[max]={0};
    printf("Enter the no. of nodes\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Array is:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
            printf("\n");
    }
dfs(a,visited,0,n);
}

void dfs(int a[][max],int visited[],int start,int n)
{
    int s[max],top=-1,i;
    char col[max];
    for(i=0;i<n;i++)
        col[i]='w';
    s[++top]=start;
    col[start]='b';
    while(top!=-1)
    {
        start=s[top--];
        visited[start]=1;
        printf("\n%c",start+65);
        for(i=0;i<n;i++)
        {
            if(a[start][i] && visited[i]==0 && col[i]=='w')
            {
                s[++top]=i;
                col[i]='b';
            }
        }
    }
}
