#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct P
{
    int v;
    int p;
};
P a[500005];
int c[500005],r[500005],n;

bool comp(const P& x,const P& y)
{
    return x.v<y.v;
}

int lowbit(int x) { return x&(-x); }

void update(int x)
{
    while(x<=n)
    {
        c[x]++;
        x+=lowbit(x);
    }
}

int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}

int main()
{
    while(~scanf("%d",&n) && n!=0)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].p=i;
        }
        sort(a+1,a+n+1,comp);
        for(int i=1;i<=n;i++)
            r[a[i].p]=i;
        for(int i=1;i<=n;i++) c[i]=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            update(r[i]);
            ans=ans+i-sum(r[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
