#include<bits/stdc++.h>
using namespace std;
const int N = 10001;
const int mod = 1000000007;
long long D[N];
void get_D()
{
    D[0] = D[2] = 1;
    D[1] = 0;
    for(int i=3; i<N; i++)
        D[i] = (i-1)*(D[i-1]+D[i-2])%mod;
}
int main()
{
    int n;
    get_D();
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        printf("%d\n",D[i]);

}
