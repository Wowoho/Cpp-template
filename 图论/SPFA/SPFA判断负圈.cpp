#include<bits/stdc++.h>
using namespace std;
const int maxn=300001;
const int inf =0x7ffffff;
struct edge
{
    int from,to,w,next;
}e[1000001];
int head[maxn];
int vis[maxn];
int dist[maxn];
int n,m,w,t;
int used[maxn];
void add(int i,int j,int w)
{
    e[t].from=i;
    e[t].to=j;
    e[t].w=w;
    e[t].next=head[i];
    head[i]=t++;
}
int spfa(int s)
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    dist[i]=inf;
    memset(vis,false,sizeof(vis));
    q.push(s);
    dist[s]=0;
    used[s]++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(dist[v]>dist[u]+e[i].w)
            {
                dist[v]=dist[u]+e[i].w;
                if(!vis[v])
                {
                    vis[v]=true;
                    if(++used[v]>n-1) return 0;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}
int main()
{
    int a,b,c,s,e,cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d%d",&n,&m);
        t=0;
        memset(head,-1,sizeof(head));
        memset(used,0,sizeof(used));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }

        if(!spfa(1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
