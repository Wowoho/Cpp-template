#include<bits/stdc++.h>
using namespace std;

priority_queue<int> F[1000005];
int father[1000005],son[1000005],a[1000005],n,m;
int find(int x)
{
    if(x!=father[x])
        father[x]=find(father[x]);
    return father[x];
}
void add(int x,int y)
{
    int x_root=find(x);
    int y_root=find(y);
    if(x_root!=y_root)
    {
        if(son[x_root]>=son[y_root])
        {
            father[y_root]=father[x_root];
            son[x_root]+=son[y_root];
        }
        else
        {
            father[x_root]=father[y_root];
            son[y_root]+=son[x_root];
        }
    }
}
int main()
{
    int i,j,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        father[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(i=1;i<=n;i++)
    {
        find(i);
        F[father[i]].push(a[i]);
    }
    for(i=1;i<=n-1;i++)
    {
        int t=F[father[i]].top();
        F[father[i]].pop();
        printf("%d ",t);
    }
    printf("%d",F[father[n]].top());
    return 0;
}
