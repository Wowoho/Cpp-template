#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 1000
int father[MAX], son[MAX];
int v, l;

struct Kruskal //存储边的信息
{
	int a;
	int b;
	int value;
};

bool cmp(const Kruskal & a, const Kruskal & b)
{
	return a.value < b.value;
}

int unionsearch(int x) //查找根结点+路径压缩 ********************************************
{
	if(x != father[x] )
        father[x]=unionsearch(father[x]);
    return father[x];
}

bool join(int x, int y) //合并
{
	int root1, root2;
	root1 = unionsearch(x);
	root2 = unionsearch(y);
	if(root1 == root2) //为环
		return false;                                     //并查集
	else if(son[root1] >= son[root2])
		{
			father[root2] = root1;
			son[root1] += son[root2];
		}
		else
		{
			father[root1] = root2;
			son[root2] += son[root1];
		}
	return true;
}                                       //*****************************************

int main()
{
	int ncase, ltotal, sum, flag;
	Kruskal edge[MAX];
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d%d", &v, &l);
		ltotal = 0, sum = 0, flag = 0;
		for(int i = 1; i <= v; ++i) //初始化
		{
			father[i] = i;
			son[i] = 1;
		}
		for(int i = 1; i <= l ; ++i)
		{
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].value);
		}
		sort(edge + 1, edge + 1 + l, cmp); //按权值由小到大排序
		for(int i = 1; i <= l; ++i)
		{
			if(join(edge[i].a, edge[i].b))
			{
				ltotal++; //边数加1
				sum += edge[i].value; //记录权值之和
			//	cout<<edge[i].a<<"->"<<edge[i].b<<endl;   //输出该边
			}
			if(ltotal == v - 1) //最小生成树条件：边数=顶点数-1
			{
				flag = 1;
				break;
			}
		}
		if(flag) printf("%d\n", sum);
		else printf("data error.\n");
	}
	return 0;
}
