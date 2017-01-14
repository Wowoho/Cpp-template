#include<stdio.h>
#define N 500001
int p[N];
int main()
{
	int n,t,i,j;
	for(i=1;i<N;i++)
	  p[i]=1;
	for(i=2;i<=N/2;i++)
	{
		for(j=2;j*i<N;j++)
			p[j*i]+=i;
	}
	scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        printf("%d\n",p[t]);
    }
return 0;
}
