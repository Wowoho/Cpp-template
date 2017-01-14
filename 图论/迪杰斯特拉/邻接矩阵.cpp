#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 510;
const int INF = 999999999;
int w[N][N]; //邻接矩阵
bool done[N]; //若d[i]不再更新，则done[i]=true, 也即结点纳入了解集
int d[N]; //d[i]记录从起点到结点i的最短路径长度

void init(int n)
{
    int i, j;

    for (i = 0; i <= n; i++)
    {
        w[i][i]=0;
        for (j = i+1; j <= n; j++)
            w[i][j] = w[j][i] = INF;
    }
}
void dijkstra(int star, int n)
{
    int i, j, minn, x, y;

    memset(done, false, sizeof (done));
    for (i = 0; i < n; i++)
        d[i] = INF;
    d[star] = 0;
    for (j = 0; j < n; j++){
        //选择d值最小的点作为起点x（d[x]已经确定了）
        minn = INF;
        for (i = 0; i < n; i++)
        {
            if (done[i] == false && d[i] < minn)
            {
                minn = d[i];
                x = i;
            }
        }
        done[x] = 1;
        for (y = 0; y < n; y++)
        {
            if (w[x][y] != 0 && d[y] > d[x]+w[x][y])
                d[y] = d[x]+w[x][y];
        }
    }
}

int main()
{
    int V, E, s, e, val;
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &V, &E);
        init(V);
        for(int i = 1; i <= E; i++)
        {
            scanf("%d%d%d", &s, &e , &val);
            if(w[s][e] > val)
                w[s][e] = w[e][s] = val;
        }
        scanf("%d", &s);
        dijkstra(s, V);
        printf("Case %d:\n",cas);
        for(int i = 0; i < V ;i++)
        {
            if(d[i] != INF)
                printf("%d\n",d[i]);
            else
                printf("Impossible\n");
        }
    }
    return 0;
}

