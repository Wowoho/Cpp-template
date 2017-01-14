#include<stdio.h>
#include<string.h>
int mat[1005][1005],n;
int lowbit(int x) { return x&(-x); }
void add(int x,int y,int val)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            mat[i][j]+=val;
}
int sum(int x,int y)
{
    int s=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            s+=mat[i][j];
    return s;
}
int main()
{
    int t,x,q,i,ans;
    int x1,x2,y1,y2;
    char c[2];
    scanf("%d",&t);
    while(t--)
    {
        memset(mat,0,sizeof(mat));
        scanf("%d%d",&n,&q);
        while(q--)
        {
            scanf("%s",&c);
            if(c[0]=='C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++; x2++; y1++; y2++;
                add(x2,y2,1);
                add(x1-1,y1-1,1);
                add(x1-1,y2,1);
                add(x2,y1-1,1);
            }
            else
            {
                scanf("%d%d",&x1,&y1);
                ans=sum(x1,y1);
                printf("%d\n",ans%2);
            }
        }
        printf("\n");
    }

    return 0;
}
