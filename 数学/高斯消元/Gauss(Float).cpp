#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define esp 1e-9using
namespace std;
const int maxn = 105;
const int dir[4][2]= {{1,1},{-1,1},{1,-1},{-1,-1}};
double a[maxn][maxn],x[maxn];
double b[maxn][maxn];
bool free_x[maxn];
int row,col,w,h;
void Debug()
{
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)printf("%.0f ",a[i][j]);
        printf("/n");
    }
    printf("/n");
}
void swaprowxy(int x,int y)
{
    for(int i=1; i<=col; i++)
    {
        double tp=a[x][i];
        a[x][i]=a[y][i];
        a[y][i]=tp;
    }
}
bool is_zero(double x)
{
    if(abs(x)<=esp) return 1;
    return 0;
}
void Gauss()
{
    int r,c;
    for(r=1,c=1; r<=row&&c<=col; r++,c++)
    {
        int maxr=r;
        for(int i=r+1; i<=row; i++)if(abs(a[i][c])>abs(a[maxr][c])) maxr=i;
        if(maxr!=r)swaprowxy(maxr,r);
        if(is_zero(a[r][c]))
        {
            r--;
            continue;
        }
        for(int i=r+1; i<=row; i++)
        {
            if(is_zero(a[i][c])) continue;
            double t=a[i][c]/a[r][c];
            for(int j=1; j<=col; j++)
            {
                a[i][j]-=a[r][j]*t;
            }
        }
    }
    for(int i=row; i>=1; i--)
    {
        double temp=a[i][col];
        for(int j=row; j>i; j--)
        {
            if(!is_zero(a[i][j])) temp-=a[i][j]*x[j];
        }
        if(!is_zero(a[i][i])) x[i]=temp/a[i][i];
    }
}
bool in_bounce(int x,int y)
{
    if(x<=h&&y<=w&&x>0&&y>0) return 1;
    return 0;
}
int main()
{
    int d;
    bool sign=0;
    while(scanf("%d%d%d",&w,&h,&d)) //列数和行数
    {
        if(w==0&&h==0) break;
        if(sign) printf("/n");
        sign=1;//增广矩阵的行列
        row=w*h;
        col=w*h+1;
        memset(a,0,sizeof(a));
        memset(free_x,0,sizeof(free_x));
        memset(x,0,sizeof(x));
        for(int i=1; i<=h; i++)for(int j=1; j<=w; j++)    scanf("%lf",&b[i][j]);
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                int num=0;
                for(int dx=0; dx<=d; dx++)for(int dy=0; dy<=d-dx; dy++)
                    {
                        for(int dd=0; dd<4; dd++)
                        {
                            int nx=i+dir[dd][0]*dx,ny=j+dir[dd][1]*dy;
                            int pos=(nx-1)*w+ny;
                            if(in_bounce(nx,ny)&&!a[(i-1)*w+j][pos])
                            {
                                num++; //每一个方程的曼哈顿距离小于等于d的个数
                                a[(i-1)*w+j][pos]=1;
                            }
                        }
                    }
                a[(i-1)*w+j][row+1]=num*b[i][j];
            }
        }
        Gauss();
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                printf("%8.2f",x[(i-1)*w+j]);
            }
            printf("/n");
        }
    }
    return 0;
