#include<stdio.h>
int mo(int a,int b,int M)
{
	int ans=1;
	while(b != 0)
		{
		if(b % 2 == 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
		}
	return ans;
}
int main()
{
	int a, b, M;
	scanf("%d%d%d",&a,&b,&M);
	printf("%d",mo(a,b,M));
}

