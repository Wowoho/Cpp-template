map<long long>f;
const long long Mod=1000000007;
long long F(long long n)
{
    if(f.count(n)) return f[n];
    long long k=n/2;
    if(n%2==0)
    {
        return f[n]=(f[k]*f[k]+f[k-1]*f[k-1])%Mod;
    }
    else
    {
        return f[n]=(f[k]*f[k+1]+f[k-1]*f[k])%Mod;
    }
}
