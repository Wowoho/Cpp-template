#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
vector<pair<int,int> > edge[MAXN];
int V;
int main()
{
    int a,b,val;
    scanf("%d",&V);
    for(int i=1;i<V;i++)
    {
        scanf("%d%d%d",&a,&b,&val);
        edge[a].push_back(make_pair(val,b));
        edge[b].push_back(make_pair(val,a));
        ///无向图加双边
    }

    for(int i=1;i<=V;i++)
    {
        printf("%d\n",i);
        for(int j=0; j<edge[i].size(); j++)
            printf("%d %d\n",edge[i][j].second,edge[i][j].first);
    }

    return 0;
}
