#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
const int INF=99999999;
int V,E;
int dist[1005];
///图的邻接表，保存成对（连接的定点序号+边线+权值）
vector<pair<int,int> > adj[MAXN];
void dijkstra(int src)
{
    dist[src]=0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        ///如果存在比当前更短的路径，则忽略该路径
        if(dist[here] < cost)
            continue;
        for(int i=0;i<adj[here].size();i++)
        {
            int there = adj[here][i].second;///
            int nextDist = cost + adj[here][i].first;
            ///更新最短路
            if(dist[there]>nextDist)
            {
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
}

int main()
{
    int a,b,val;
    scanf("%d%d",&V,&E);
    for(int i=1;i<=V;i++)
        dist[i] = INF;
    for(int i=0;i<E;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        adj[a].push_back(make_pair(val,b));
    }
    int start;
    scanf("%d",&start);
    dijkstra(start);
    for(int i=1; i<=V ;i++)
        printf("%d ",dist[i]);
    return 0;
}
