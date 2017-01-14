#include<bits/stdc++.h>
using namespace std;
struct P
{
    int val;
    int pos;
};

bool comp(P x,P y)
{
    return x.val < y.val;
}

P a[1000];
int main()
{
    int b[1000],i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i].val);
        a[i].pos=i;
    }
    sort(a+1,a+n+1,comp);
    int last=-1 , rank;
    for(i=1;i<=n;i++)
    {
        if(a[i].val!=last)
        {
            last=a[i].val;
            b[i]=i;
            rank=i;
        }
        else
            b[i]=rank;
    }
    for(i=1;i<=n;i++)
        a[i].val=b[a[i].pos];
    for(i=1;i<=n;i++)
        printf("%d ",a[i].val);
    return 0;
}
