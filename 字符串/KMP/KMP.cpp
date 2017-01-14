#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 10010

char a[maxn*100], b[maxn];
int Next[maxn], n, m;

void Get_Next (char b[], int M)
{
    int i, j;
    j = Next[0] = -1;
    i = 0;

    while (i < M)
    {
        while (j!=-1 && b[i]!=b[j])
            j = Next[j];

        Next[++i] = ++j;
    }
}

int kmp (char a[], char b[],int N, int M)
{
    int ans, i, j;
    i = j = ans = 0;

    Get_Next (b, M);

    while (i < N)
    {
        while (j!=-1 && a[i] != b[j])
            j = Next[j];

        j++, i++;

        if (j == M)
        {
            ans ++;
            ///printf("%d -> %d\n", i, i+M-1); ///输出找到的位置
            j = Next[j];  ///匹配成功后，当做失配，移动j到Next处
        }
    }
    return ans;
}

int main ()
{
    int T;
    scanf ("%d", &T);

    while (T --)
    {
        scanf ("%s%s", b, a);

        n = strlen (a);
        m = strlen (b);

        printf("%d\n", kmp(a, b, n ,m));
    }
    return 0;
}
