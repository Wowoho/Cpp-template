#include<queue>
#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
#define INF 999999
#define M 2002

vector<pair<int,int> > edge[M];
int n;
int maxx;
int sum[M];
bool flag[M];
int bfs(int start)
{
    queue<int>f;
    int i, m, now, key;
    maxx = 0;

    memset(flag, false, sizeof(flag));
    f.push(start);
    while (!f.empty())
    {
        now = f.front();
        for (i = 0; i < edge[now].size(); i++)
        {
            int next=edge[now][i].second;
            if (!flag[next])
            {
                ///printf("%d\n",next);
                flag[next] = true;
                f.push(next);
                sum[next] = sum[now] + edge[now][i].first;
                if (sum[next] > maxx)
                {
                    maxx = sum[next];
                    key = next;
                }
            }
        }
        f.pop();
    }
    return key;
}
int main()
{
    int i, j, k, dis, key, cas;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        for (i = 1; i < n; i++)
        {
            scanf("%d%d%d", &j, &k, &dis);
            edge[j].push_back(make_pair(dis,k));
            edge[k].push_back(make_pair(dis,j));
        }
        sum[1] = 0;
        key = bfs(1);
        sum[key] = 0;
        key = bfs(key);
        printf("%d\n", maxx);
    }
    return 0;
}
