#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
int a[MAXN],num[MAXN];///a为离散化前，num为离散化后
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        num[i]=a[i];
    }

    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)                         ///离散化
        num[i] = lower_bound(a+1,a+n+1,num[i])-a;

    for(int i=1;i<=n;i++)
        printf("%d ",num[i]);
    return 0;
}
