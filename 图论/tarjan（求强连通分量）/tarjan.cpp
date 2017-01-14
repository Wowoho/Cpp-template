#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAXN 10010
#define MAXM 100010

struct Edge
{
      int v, next;
}edge[MAXM];    ///边结点数组

int first[MAXN], stack[MAXN], DFN[MAXN], Low[MAXN], Belong[MAXM];
/// first[]头结点数组,stack[]为栈,DFN[]为深搜次序数组，Belong[]为每个结点所对应的强连通分量标号数组
/// Low[u]为u结点或者u的子树结点所能追溯到的最早栈中结点的次序号
int instack[10010];  /// instack[]为是否在栈中的标记数组
int n, m, scnt, top, tot;

void init()
{
    scnt = top = tot = 0;    ///初始化连通分量标号，栈顶指针为0， 次序计数器
    memset(first, -1, sizeof(first));
    memset(DFN, 0, sizeof(DFN));   ///结点搜索的次序编号数组为0，同时可以当是否访问的数组使用
}

void read_graph(int u, int v) ///构建邻接表
{
     edge[tot].v = v;
     edge[tot].next = first[u];
     first[u] = tot++;
}

void Tarjan(int v)       ///Tarjan算法求有向图的强连通分量
{
     int min, t;
     DFN[v] = Low[v] = ++tot;    /// cnt为时间戳
     instack[v] = 1;    //标记在栈中
     stack[top++] = v;      //入栈
     for(int e = first[v]; e != -1; e = edge[e].next)
     {   ///枚举v的每一条边
           int j = edge[e].v;   /// v所邻接的边
           if(!DFN[j])
           {   /// 未被访问
               Tarjan(j);    /// 继续向下找
               if(Low[v] > Low[j]) Low[v] = Low[j];  /// 更新结点v所能到达的最小次数层
           }
           else if(instack[j] && DFN[j] < Low[v])
           {   ///如果j结点在栈内,
               Low[v] = DFN[j];
           }
     }
     if(DFN[v] == Low[v])
     {     ///如果节点v是强连通分量的根
           scnt++;   ///连通分量标号加1
           printf("强连通分量%d: ",scnt);
           do
           {
               t = stack[--top];   ///退栈
               instack[t] = 0;   ///标记不在栈中
               printf("%d ",t);
               Belong[t] = scnt;   ///出栈结点t属于cnt标号的强连通分量
           }while(t != v);  ///直到将v从栈中退出
           printf("\n");
     }
}

void solve()
{
     for(int i = 1; i <= n; i++)   ///枚举每个结点，搜索连通分量
        if(!DFN[i])  //未被访问
           Tarjan(i);  //则找i结点的连通分量
}

int main()
{
    while(scanf("%d%d",&n,&m) && (n || m))
    {
        init();
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            read_graph(u, v);
        }
        solve();     //求强连通分量

    }
    return 0;
}
