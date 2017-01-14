//大组合数取余
//C(n,m) mod P
#include<bits/stdc++.h>
using namespace std;

int fac[100003];
void init(int M)
{
    fac[0]=1;
    for(int i=1;i<=M;i++)
        fac[i]=i*fac[i-1]%M;
}

int kuaisumo(int a,int b,int M)
{
	int ans=1;
	while(b!=0)
		{
		if(b%2==1) ans=(ans*a)%M;
		a=(a*a)%M;
		b/=2;
		}
	return ans;
}

int Lucas(int n,int m,int M)
{
    int ret=1;
    while(n && m)
    {
        int nn=n%M,mm=m%M;
        if(nn < mm) return 0;
        ret=(ret*fac[nn]) % M * kuaisumo(fac[mm]*fac[nn-mm]%M,M-2,M) % M;
        n/=M;
        m/=M;
    }
    return ret;
}

int main()
{
    int t;
    int n,m,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&p);
        init(p);
        printf("%d\n",Lucas(n,m,p));
    }
    return 0;
}

