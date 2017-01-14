
/*

struct RMQ {
    int n;
    int st[20][Maxn];
    void init(int v[], int L) {
        int i, j, k; n = L;
        for(i = 0; i <= n; i++) st[0][i] = v[i];
        for(j = 1, k = 0; (1<<j) <= n; j++, k++) {
            for(i = 0; i + (1<<j) - 1<= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1<<k)]);
            }
        }
    }
    int query(int l, int r) {
//        int k = 31 - __builtin_clz(r - l + 1);
//        int k = kk[r - l + 1];
        return min(st[k][l], st[k][r - (1<<k) + 1]);
    }
}rmq1, rmq2;

*/
//找最近的公共祖先LCA
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 100005
#define maxlog (log(maxn)/log(2))
using namespace std;
int fa[100][maxn],dep[maxn],dg[maxn];
map<string,int> mp;
map<int,string> remp;
vector<int> vt[maxn];
int cnt,root;

void dfs(int x,int p,int d)
{
    fa[0][x]=p;
    dep[x]=d;
    int i,j;
    for(i=0;i<vt[x].size();i++)
    dfs(vt[x][i],x,d+1);
}
void init()
{
    int i,mlog=(log(cnt)/log(2));
    dfs(root,-1,0);
    for(int k=0;k+1<mlog;k++)
    {
        for(int v=0;v<cnt;v++)
        {
            if(fa[k][v]<0)fa[k+1][v]=-1;
            else fa[k+1][v]=fa[k][fa[k][v]];
        }
    }
}
int lca(int u,int v)
{
    int i,j,mlog=(log(cnt)/log(2));;
    if(dep[u]>dep[v])swap(u,v);
    for(i=0;i<mlog;i++)
    {
        if((dep[v]-dep[u])>>i &1)
        v=fa[i][v];
    }
    if(u==v)return u;

    for(int k=mlog-1;k>=0;k--)
    {
        if(fa[k][u]!=fa[k][v])
        {
            u=fa[k][u];
            v=fa[k][v];
        }
    }

    return fa[0][u];
}
int main()
{
//  read;
    int n,u,v;
    cnt=1;
    int i,q;
    string father,son;
    memset(dg,0,sizeof(dg));
    scanf("%d",&n);
    while(n--)
    {
        cin>>father>>son;
        if(!mp[father])
        {
            mp[father]=cnt;
            remp[cnt]=father;
            cnt++;
        }
        if(!mp[son])
        {
            mp[son]=cnt;
            remp[cnt]=son;
            cnt++;
        }
        u=mp[father];v=mp[son];
        vt[u].push_back(v);
        dg[v]++;
    }
    for(i=1;i<cnt;i++)
    if(dg[i]==0)
    {
        root=i;
        break;
    }
    init();

    scanf("%d",&q);
    while(q--)
    {
        cin>>father>>son;
        int res=lca(mp[father],mp[son]);
        cout<<remp[res]<<endl;
    }

}
