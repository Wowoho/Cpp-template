#include<stdio.h>
int mi(int a,int b)
{
	int ans=1;
	while(b != 0)
		{
		if(b % 2 == 1) ans = ans * a;
		a = a * a;
		b /= 2;
		}
	return ans;
}
int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	printf("%d",mi(a,b));
}
