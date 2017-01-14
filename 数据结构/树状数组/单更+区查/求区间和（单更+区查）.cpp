#include<stdio.h>
int a[1000],tree[1000],n;

void updata(int i,int k)
{
    while(i<=n)
    {
        tree[i]+=k;
        i=i+(i&(-i));
    }
}
int sum(int i)
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
    int i,r,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        tree[i]=0;
    }
    scanf("%d %d",&l,&r);
    for(i=1;i<=n;i++)
        updata(i,a[i]);
    printf("%d",sum(r)-sum(l-1));
}
