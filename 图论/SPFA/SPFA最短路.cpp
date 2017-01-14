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
int n,m,t;
void add(int i,int j,int w)
{
    e[t].from=i;
    e[t].to=j;
    e[t].w=w;
    e[t].next=head[i];
    head[i]=t++;
}
void spfa(int s)
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    dist[i]=inf;
    memset(vis,false,sizeof(vis));
    q.push(s);
    dist[s]=0;
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
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int a,b,c,s,e;
    scanf("%d%d",&n,&m);
    t=0;
    memset(head,-1,sizeof(head));
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    scanf("%d%d",&s,&e);
    spfa(s);
    if(dist[e]==inf) printf("-1\n");
    else printf("%d\n",dist[e]);
    return 0;
}
