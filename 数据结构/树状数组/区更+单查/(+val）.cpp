#include<bits/stdc++.h>
using namespace std;
int a[1000],tree[1000],n;

void Add(int i,int k)
{
    while(i<=n)
    {
        tree[i]+=k;
        i=i+(i&(-i));
    }
}
int Quriy(int i)
{
    int s=0;
    while(i>0)
    {
        s+=tree[i];
        i=i-(i&(-i));
    }
    return s;
}

int main()
{
    a[0]=0;
    tree[0]=0;
    int i,r,l,op,t,x,val;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        Add(i,a[i]);
        Add(i+1,-a[i]);
    }
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&l,&r,&val);
            Add(l,val);
            Add(r+1,-val);
        }
        else
        {
            scanf("%d",&x);
            printf("%d",Quriy(x));
        }
//        for(int j=1;j<=n;j++)
//            printf("%d ",Quriy(j));
//        printf("\n");
    }

    return 0;
}
