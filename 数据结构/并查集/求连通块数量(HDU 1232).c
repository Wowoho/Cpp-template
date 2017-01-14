//并查集——求连通块数量——（HDU 1232）
//2016-8

#include<stdio.h>

int father[1001],son[1001],n,m,a,b;

int find(int x)
{
    if(x!=father[x])
        father[x]=find(father[x]); //路径压缩
    return father[x];
}


void add(int x,int y)
{
    int x_root=find(x);
    int y_root=find(y);
    if(x_root!=y_root)
    {
        if(son[x_root]>=son[y_root])    //按秩（son的数量）合并
        {
            father[y_root]=father[x_root];
            son[x_root]+=son[y_root];
        }
        else
        {
            father[x_root]=father[y_root];
            son[y_root]+=son[x_root];
        }
    }
}

int main()
{
    int i,ans;
    while (~scanf("%d",&n) && n!=0)
    {
        scanf("%d",&m);
        ans=-1;  //或0，依题意而定
        for(i=1;i<=n;i++)
        {
            father[i]=i;
            son[i]=1;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(i=1;i<=n;i++)
            if(i==father[i])
                ans++;
        printf("%d\n",ans);
    }


    return 0;
}
