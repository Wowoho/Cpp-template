
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#define N 1000
#define M 1<<30
using namespace std;

struct map            //比如节点1 与节点2 3都连接 这里记录的num就有2个 len数组是记录与2 3节点的距离， road记录的是2 3标号
{
    int len[N];
    int road[N];
    int num;
}point[N]={0};

struct que
{
    int road,len;
}set[N]={0};

bool operator <(const que &x,const que &y)//最小堆
{
    if(x.len>y.len) return true;
    return false;
}
priority_queue<que> mini;

int n,m;


//dist记录的是节点x到其他节点的最短路径
void Dijkstra(int x,int y)
{
    int i,j,k,len,road,dist[N]={0},mid2;
    bool check[N]={0};
    que mid;
    for(i=0;i<=m;i++)
    {
        dist[i]=M;
    }
    for(i=0;i<point[x].num;i++)
    {
        set[i].road=point[x].road[i];
        set[i].len=point[x].len[i];
        mini.push(set[i]);
        dist[point[x].road[i]]=point[x].len[i];
    }
    while(!mini.empty())
    {
        mid=mini.top();
        mini.pop();
        //printf("now checking %d\n",mid.road);
        if(check[mid.road]) continue;
        check[mid.road]=true;
        k=mid.road;
        for(j=0;j<point[k].num;j++)
        {
            len=point[k].len[j];
            road=point[k].road[j];
            mid2=dist[k]+len;
            if(dist[road]>mid2)
            {
                dist[road]=mid2;
                set[i].road=road;set[i].len=mid2;
                mini.push(set[i]);
            }
        }
    }
    printf("%d\n",dist[y]);
}

int main()
{
    int i,a,b,r;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&r);
        point[a].road[point[a].num]=b;
        point[a].len[point[a].num]=r;
        point[a].num++;
    }
    scanf("%d",&r);
    while(r--)
    {
        scanf("%d %d",&a,&b);
        Dijkstra(a,b);
    }
    //scanf("%d",&i);
}
