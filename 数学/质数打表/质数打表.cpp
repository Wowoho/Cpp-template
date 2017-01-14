#include<bits/stdc++.h>
#define N 10000
int com[N],prime[N],num;
void getprime(int n)
{
    memset(com,0,sizeof(com));
    num =1;
    for(int i=2;i<=n;i++)
    {
        if(!com[i])
        {
            prime[num++]=i;
            for(int j=i+i;j<=n;j+=i)
                com[j]=1;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getprime(n);
    for(int i=1;i<=num;i++)
        printf("%d  ",prime[i]);
}
