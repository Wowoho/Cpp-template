//线段树单个点修改&区间查询
//以最大值为例
#include<bits/stdc++.h>
using namespace std;

const int e = 100006;
struct qq
{
        int maxx;
} tree[4 * e]; //线段树要开4倍的点的个数
int n, t, a, b;

void updata(int l, int r, int root)
{
        if (r < a || l > a)
        {
                return;
        }
        if (r == l)
        {
                tree[root].maxx = b;
                return;
        }

        int mid = (l + r) / 2;
        updata(l, mid, root * 2);
        updata(mid + 1, r, root * 2 + 1);
        tree[root].maxx = max(tree[root * 2].maxx, tree[root * 2 + 1].maxx);
}


int search(int l, int r, int root)
{
        if (l > b || r < a)
        {
                return (-999999999);
        }

        if (l >= a && r <= b)
        {
                return (tree[root].maxx);
        }

        int mid = (l + r) / 2;
        return (max( search(l, mid, root * 2), search(mid + 1, r, root * 2 + 1)));
}

int main()
{
        //freopen("in.in","r",stdin);

        memset(tree, 0, sizeof(tree));
        cin >> n;

        for (int i = 0; i < n; i++)
        {
                scanf("%d%d%d", &t, &a, &b);

                if (t == 1)
                {
                        updata(1, n, 1);        //将点a的值改为b
                }
                if (t == 2)
                {
                        cout << search(1, n, 1) << endl;        //查找区间a(含)到b(含)的最大值;
                }
        }

        //fclose(stdin);    fclose(stdout);
        return 0;
}
