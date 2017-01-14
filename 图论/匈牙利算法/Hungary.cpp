#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
int uN, vN, M; ///uN为u类节点个数, vN为v类节点个数，M为边数
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];

bool dfs(int u) ///寻找增广路
{
    int v;
    for(v=0 ;v<vN ;v++)
        if(g[u][v] && !used[v])
        {
            used[v]=true;
            if(linker[v]==-1 || dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    return false;
}

int Hungary()
{
    int ans=0;
    int u;
    //memset(g,0,sizeof(g));
    memset(linker,-1,sizeof(linker));
    for(u=0 ;u<uN; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) ans++;
    }
    return ans;
}

int main()
{
    int x,y;
    scanf("%d%d%d",&uN,&vN,&M);
    for(int i=1;i<=M;i++)
    {
        scanf("%d%d",&x,&y);
        g[x-1][y-1]=1;
    }
    printf("%d",Hungary());
    return 0;
}
