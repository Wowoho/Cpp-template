#include<stdio.h>
#define MAX 99999
#define MIN -99999
int mat[101][101] , path[101][101],n;
void Floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(mat[i][j] > mat[i][k] + mat[k][j])
                {
                    mat[i][j]=mat[i][k]+mat[k][j];
                    //path[i][j]=path[i][k];
                }
}
int main()
{
    int m;
    int i,j,k,t;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            mat[i][j]=MAX;
    for(k=1;k<=m;k++)
    {
        scanf("%d %d %d",&i,&j,&t);
        mat[i][j]=t;
        mat[j][i]=t;
    }
    Floyd();
    scanf("%d%d",&i,&j);
    printf("%d",mat[i][j]);
}
