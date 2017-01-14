#include <cstdio>
int t, n, M, p, l, r, ans, a[131073];
char ch;
void add(int pos, int x)
{
        for (pos += M + 1; pos; pos /= 2)
        {
                a[pos] += x;
        }
}
int que(int l, int r)
{
        for (l += M, r += M + 2, ans = 0; l ^ r ^ 1; l >>= 1, r >>= 1)
        {
                ans += ((l & 1) ? 0 : a[l + 1]) + ((r & 1) ? a[r - 1] : 0);
        }
        return ans;
}
int main()
{
        scanf("%d", &t);
        for (int T = 1; T <= t; T++)
        {
                printf("Case %d:\n", T);
                scanf("%d", &n);
                M = 1;
                n += 2;
                while (M < n)
                {
                        M *= 2;
                }
                M--;
                for (int i = 1; i <= M + n + 1; i++)
                {
                        a[i] = 0;
                }
                for (int i = 1; i <= n; i++)
                {
                        scanf("%d", &p);
                        add(i, p);
                }
                for (ch = getchar(); ch != 'E' && ch != 'Q' && ch != 'A' && ch != 'S'; ch = getchar());
                while (ch != 'E')
                {
                        switch (ch)
                        {
                        case'Q':
                                getchar();
                                getchar();
                                getchar();
                                getchar();
                                scanf("%d%d", &l, &r);
                                printf("%d\n", que(l, r));
                                break;
                        case 'A':
                                getchar();
                                getchar();
                                scanf("%d%d", &l, &r);
                                add(l, r);
                                break;
                        case 'S':
                                getchar();
                                getchar();
                                scanf("%d%d", &l, &r);
                                add(l, -r);
                                break;
                        }
                        for (ch = getchar(); ch != 'E' && ch != 'Q' && ch != 'A' && ch != 'S'; ch = getchar());
                }
                getchar();
                getchar();
        }
        return 0;
}
