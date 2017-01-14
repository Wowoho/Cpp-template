#include<bits/stdc++.h>
using namespace std;
const int N = 1100;
const int INF = 2000000000;
struct Node
{
    int to, cap, rev; ///
};
vector<Node> V[N];
bool used[N];

void Add(int from, int to, int cap)
{
    V[from].push_back((Node){to, cap, V[to].size()});
    V[to].push_back((Node){from, 0, V[from].size()-1});
}

int dfs(int st, int ed, int f)
{
    if(st == ed)
        return f;
    used[st] = true;
    for(int i=0; i<V[st].size(); i++)
    {
        Node &tmp = V[st][i];
        if(used[tmp.to]==false && tmp.cap>0)
        {
            int d = dfs(tmp.to, ed, min(f, tmp.cap));
            if(d > 0)
            {
                tmp.cap -= d;
                V[tmp.to][tmp.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int Max_flow(int st, int ed)
{
    int flow = 0;
    while(1)
    {
        memset(used, false, sizeof used);
        int f = dfs(st, ed, INF);
        if(f == 0)
            return flow;
        flow += f;
    }
}

int main()
{
    int n, m, st, ed;
    while(~scanf("%d%d", &m, &n))
    {
        for(int i=0; i<=n; i++) V[i].clear();
        for(int i=1; i<=m; i++)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            Add(a, b, w);
        }
        scanf("%d%d", st, ed);
        int ans = Max_flow(st, ed);
        printf("%d\n", ans);
    }


    return 0;
}
