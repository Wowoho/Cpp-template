    //朴素版Dijkstra算法

    //输入一个图的矩阵，假定两点不相邻则权值为0
    //输出每个顶点的最短路径长度,可以打印指定顶点的路径

    //Dijkstra算法跟Prim算法很像
    //相同的地方是:
    //两者都有一个已经求得"MST"和已经求得"最短路"的集合
    //每纳入一个结点x到集合，更新的是集合外与x直接相连的点的key[]或者d[];
    //不同地方就是:
    //Prim中，key的意义是某点到集合 与之最近元素 的边权
    //Dijkstra中,d的意思是某点到集合 给定起点元素 的最"短"路的边权和

    /*
    Dijkstra算法
    每个顶点清除标记;
    d[起点] = 0, d[其他点] = INF;

    循环n次
    {
        在未标记的结点中，选择d值最小的结点x;
        标记结点x;
        对于结点x,走遍所有边(x,y),更新d[y] = min(d[y], d[x]+w[x][y]);
        //x新纳入已求得“最短路”的集合中，正因为x进入，可能邻接到新的点（更新初始值）
        //也可能有新路径到之前更新的点，此时就需要检查是否更新了
    }

    */


     /*
    参考测试数据
    来源——wiki百科的Dijkstra算法gif动态图
    输入点的个数（程序中编程从0开始）
    输入起点
    输入矩阵
    输入任意点（求其路径）

    6
    0
    0  7  9  0  0  14
    7  0  10 15 0  0
    9  10 0  11 0  2
    0  15 11 0  6  0
    0  0  0  6  0  9
    14 0  2  0  9  0
    3

    */

    #include <iostream>
    #include<cstdio>
    #include<cstring>
    using namespace std;

    const int N = 110;
    const int INF = 999999999;
    int w[N][N]; //邻接矩阵
    bool done[N]; //若d[i]不再更新，则done[i]=true, 也即结点纳入了解集
    int d[N]; //d[i]记录从起点到结点i的最短路径长度
    int par[N]; //par[i]保存记录i的父亲结点

    //创建图
    void createGraph(int n)
    {
        int i, j;

        for (i = 0; i != n; i++)
            for (j = 0; j != n; j++)
                scanf("%d", &w[i][j]);
    }

    //star:单源起点
    //n:结点数目
    void dijkstra(int star, int n)
    {
        int i, j, min, x, y;

        //初始化d[], v[]
        memset(done, false, sizeof (done));
        for (i = 0; i != n; i++)
            d[i] = INF;

        //设置起点
        d[star] = 0;
        //规定起点的父母也是自己
        par[star] = star;

        //循环n次
        for (j = 0; j != n; j++){
            //选择d值最小的点作为起点x（d[x]已经确定了）
            min = INF;
            for (i = 0; i != n; i++) {
                if (done[i] == false && d[i] < min) {
                    min = d[i];
                    x = i;
                }
            }
            //x的d[i]已经确定了
            done[x] = 1;
            //对所有x的边(x, y)
            for (y = 0; y != n; y++) {
                if (w[x][y] != 0 && d[y] > d[x]+w[x][y]) {
                    d[y] = d[x]+w[x][y];
                    par[y] = x;
                }
            }
        } //循环n次
    }

    //star:单源起点
    //i:当前结点
    void printPath(int star, int i)
    {
        //到祖先了
        if (star == i) {
            cout << i << " ";
            return;
        }
        printPath(star, par[i]);
        cout << i << " ";
    }

    int main()
    {
        int n, star, end;

      //  cout << "输入结点个数n:" << endl;
        cin >> n;
       // cout << "请输入该图的邻接矩阵:" << endl;
        createGraph(n);
        // cout << "请输入起点[0, n-1]:" << endl;
        cin >> star>>end;
        dijkstra(star, n);

       /* cout << "依次打印n个结点其父母结点:" << endl;
        for (int i = 0; i != n; i++) {
            cout << par[i] << " ";
        }
        cout << endl;*/
      /*  cout << "依次打印从起点" << star
             << "到n个结点的最短距离:" << endl;
        for (int i = 0; i != n; i++) {
            cout << d[i] << " ";
        }
        cout << endl;*/
      /*  cout << "请输出结点编号[0, n-1]，以打印其最短路径经过的结点:" << endl;
        cin >> end;//0 ~ n-1*/
        printPath(star, end);
        cout << endl;
        return 0;
    }
