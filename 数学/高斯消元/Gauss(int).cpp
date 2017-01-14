/// 高斯消元解整型方方程组
/// 判断是否有小数解

#include<bits/stdc++.h>
#define LL __int64
const int maxn = 100+10;
using namespace std;
int equ, var, fn;
int a[maxn][maxn], x[maxn];
bool free_x[maxn];

int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}
int lcm(int a, int b)
{
    return a*b/gcd(a, b);
}

int Gauss()
{
    int i, j, k, max_r, col;
    int ta, tb, LCM, tmp, fx_num;
    int free_index;
    col = 0;

    for(k = 0; k<equ && col<var; k++, col++)
    {
        max_r = k;
        for(i = k+1; i < equ; i++)
            if(abs(a[i][col])>abs(a[max_r][col]))
            max_r = i;

        if(max_r != k)
            for(j = k; j < var+1; j++)
            swap(a[k][j], a[max_r][j]);

        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i = k+1; i < equ; i++)
        {
            if(a[i][col] != 0)
            {
                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                ta = LCM/abs(a[i][col]);
                tb= LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col] < 0) tb = -tb;

                for(j = col; j < var+1; j++)
                a[i][j] = a[i][j]*ta - a[k][j]*tb;
            }
        }
    }
    for(i = k; i < equ; i++)
    if(a[i][col] != 0)
    return -1;

    if(k < var)
    {
        for(i = k-1; i >= 0; i--)
        {
            fx_num = 0;
            for(j = 0; j < var; j++)
                if(a[i][j]!=0 && free_x[j])
                {
                    fx_num ++;
                    free_index = j;
                }
            if(fx_num > 1) continue;

            tmp = a[i][var];
            for(j = 0; j < var; j++)
                if(a[i][j] != 0 && j!=free_index)
                tmp -= a[i][j]*x[j];

            x[free_index] = tmp/a[i][free_index];
            free_x[free_index] = 0;
        }
        return var-k;
    }
    for(i = var-1; i >= 0; i--)
    {
        tmp = a[i][var];
        for(j = i+1; j < var; j++)
        if(a[i][j] != 0)
        tmp -= a[i][j]*x[j];

        if(tmp%a[i][i] != 0) return -2;
        x[i] = tmp/a[i][i];
    }
    return 0;
}
int main()
{
    int i, j;
    while(~scanf("%d%d", &equ, &var))
    {
        memset(a, 0, sizeof(a));
        memset(x, 0, sizeof(x));
        memset(free_x, 1, sizeof(free_x));
        for(i = 0; i < equ; i++)
        {
            for(j = 0; j < var+1; j++)
            scanf("%d",&a[i][j]);
        }

        fn = Gauss();
        if(fn == -1)
            printf("无解");
        else if(fn == -2)
        printf("有浮点数解， 无整数解");
        else if(fn > 0)
        {
            printf("无穷多解! 自由变元个数为%d\n", fn);
            for(i = 0; i < var; i++)
            {
                if(free_x[i]) printf("x%d行 是不确定的\n", i + 1);
                else printf("x%d: %d\n", i + 1, x[i]);
            }
        }
        else
        {
            for(i = 0; i < var; i++)
            printf("x%d: %d\n", i + 1, x[i]);
        }
        printf("\n");
    }
    return 0;
}
