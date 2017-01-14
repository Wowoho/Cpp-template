#include<stdio.h>
#define N (1000010)
#define mod (1000003)
__int64 a[N];
__int64 ni[N];

__int64 kuaisumo(__int64 a,__int64 b,__int64 M)
{
	__int64 ans=1;
	while(b != 0)
		{
		if(b % 2 == 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
		}
	return ans;
}

void init()
{
    __int64 i;
    a[0]=1;
    ni[0]=1;
    for(i=1;i<=N;i++)
    {
        a[i]=a[i-1]*i%mod;
        ni[i]=kuaisumo(a[i],(mod-2),mod);
    }
}

__int64 C(__int64 n, __int64 k)
{
    return ((a[n]*ni[k]%mod)*ni[n-k])%mod;
}

__int64 A(__int64 n, __int64 k)
{
    return (a[n]*ni[n-k])%mod;
}

int main()
{
    __int64 n,k,t,i,ans;
    init();
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&k);
        ans = C(n, k);
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
