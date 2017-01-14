#include<queue>
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define INF 999999
#define M 2002

int n;
int maxx;
int map[M][M], sum[M];
bool flag[M];
int bfs(int begin)
{
    queue<int>f;
    int i, m, k, key;
    maxx = 0;
    memset(flag, false, sizeof(flag));
    f.push(begin);
    while (!f.empty())
    {
        k = f.front();
        for (i = 1; i <= n; i++)
        {
            if (map[k][i] != INF && !flag[i])
            {
                flag[i] = true;
                f.push(i);
                sum[i] = sum[k] + map[k][i];
                if (sum[i] > maxx)
                {
                        maxx = sum[i];
                        key = i;
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
            for (j = i + 1; j <= n; j++)
            {
                map[i][j] = map[j][i] = INF;
            }
        for (i = 1; i < n; i++)
        {
            scanf("%d%d%d", &j, &k, &dis);
            map[j][k] = map[k][j] = dis;
        }
        sum[1] = 0;
        key = bfs(1);
        sum[key] = 0;
        key = bfs(key);
        printf("%d\n", maxx);
    }
    return 0;
}
