#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 110
int map[MAXN][MAXN];
bool visit[MAXN];
int nodenum, sum;
struct TREEedge
{
    int a,b;
    int len;
};
TREEedge lowcost[MAXN];
void prim()
{
    int temp, k;
    sum = 0;
    memset(visit, false, sizeof(visit)); //��ʼ��visit
    visit[1] = true;
    for(int i = 1; i <= nodenum; ++i){ //��ʼ��lowcost[i]
        lowcost[i].len= map[1][i];
        lowcost[i].a=1;
        lowcost[i].b=i;
    }
    for(int i = 1; i <= nodenum; ++i)//�����������ϵ㼯������СȨֵ�ı�
    {
        temp = INF;
        for(int j = 1; j <= nodenum; ++j)
            if(!visit[j] && temp > lowcost[j].len)
                temp = lowcost[k = j].len;
        if(temp == INF) break;
        visit[k] = true; //������С����������
        sum += temp;//��¼Ȩֵ֮��
        for(int j = 1; j <= nodenum; ++j) //����lowcost����
            if(!visit[j] && lowcost[j].len > map[k][j])
            {
                lowcost[j].len= map[k][j];
                lowcost[j].a=k;
                lowcost[j].b=j;
            }
    }
}

int main()
{
    int a, b, cost, edgenum;
    while(scanf("%d%d", &nodenum,&edgenum) && nodenum)
    {
        memset(map, INF, sizeof(map));
       // edgenum = nodenum * (nodenum - 1) / 2;
        for(int i = 1; i <= edgenum; ++i) //����ߵ���Ϣ
        {
            scanf("%d%d%d", &a, &b, &cost);
            if(cost < map[a][b])
                map[a][b] = map[b][a] = cost;
        }
        prim();
        printf("%d\n", sum); //��С������Ȩֵ֮��
        for(int i=2;i<=nodenum;i++)
        {
            printf("%d %d %d\n",lowcost[i].a,lowcost[i].b,lowcost[i].len);
        }

    }
    return 0;
}
