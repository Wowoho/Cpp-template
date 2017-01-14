long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

long long gbs(long long a,long long b)
{
    return a*b/gcd(a,b);
}


int gcd(int a,int b)
{
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
