#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=(int)1e9+7;

const int P=(7*17<<23)+1,r=3;

inline void mod_add(int &a,int b)
{
    if((a+=b)>=P)a-=P;
}
inline void mod_minus(int &a,int b)
{
    if((a-=b)<0)a+=P;
}
int fast_mod_pow(int a,int b)
{
    int res=1;
    for(; b; b>>=1,a=1ll*a*a%P)
        if(b&1)res=1ll*res*a%P;
    return res;
}
inline int calc_inv(int x)
{
    return fast_mod_pow(x,P-2);
}


const int N=(1<<18)+5;

int rev[N],A[N],B[N],C[N];

void DFT(int *arr,int n,bool flag)
{
    for(int i=0; i<n; i++)
        if(i<rev[i])
            swap(arr[i],arr[rev[i]]);
    for(int m=2; m<=n; m<<=1)
    {
        int g = fast_mod_pow(r,(P-1)/m);
        if(flag)
            g = calc_inv(g);
        for(int i=0; i<n; i+=m)
        {
            int cur=1;
            for(int j=0; j<(m>>1); j++)
            {
                int x = arr[i+j];
                int y = 1ll*cur*arr[i+j+(m>>1)]%P;
                mod_add(arr[i+j]=x,y);
                mod_minus(arr[i+j+(m>>1)]=x,y);
                cur = 1ll*cur*g%P;
            }
        }
    }
}
void NTT(int n,int m)
{
    int _n,S;
    for(_n=1,S=0; _n<n+m; _n<<=1,++S);
    for(int i=1; i<_n; i++)
        rev[i] = (rev[i>>1]>>1)|((i&1)<<S-1);
    for(int i=n; i<_n; i++)
        A[i]=0;
    for(int i=m; i<_n; i++)
        B[i]=0;
    DFT(A,_n,false);
    DFT(B,_n,false);
    for(int i=0; i<_n; i++)
        C[i] = 1ll*A[i]*B[i]%P;
    DFT(C,_n,true);
    int inv = calc_inv(_n);
    for(int i=0; i<_n; i++)
        C[i] = 1ll*C[i]*inv%P;
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<=m; i++)
        scanf("%d", &B[i]);

    NTT(n+1,m+1);///  Ò»¶¨Òª +1 £¡£¡£¡

    for(int i=0; i<=n+m; i++)
        printf("%d ",C[i]);
    printf("\n");
    return 0;
}
