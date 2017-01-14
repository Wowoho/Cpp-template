//寻找不大于x的元素个数
#include<bits/stdc++.h>
using namespace std;
int num[100005],n,m,x;

int bSearch(int begin, int end, int e)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid = (left + right) >> 1;
        if(num[mid] > e) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

int main()
{
    int i,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&num[i]);
    sort(num+1,num+n+1);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        ans=bSearch(1,n,x);
        printf("%d\n",ans);
    }
    return 0;
}
