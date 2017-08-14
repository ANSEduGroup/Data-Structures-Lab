#include<stdio.h>
void tower(char,char,char,int);
int main()
{
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    tower('A','C','B',n);
}
void tower(char s, char d, char m, int n)
{
    if(n==1)
        printf("%c -> %c\n",s,d);
    else
	{
        tower(s,m,d,n-1);
        tower(s,d,m,1);
        tower(m,d,s,n-1);
	}
}
