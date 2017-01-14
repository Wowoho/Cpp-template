#include<stdio.h>
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)//拓展欧几里德算法
{
   __int64 d,t;
   if(b==0)
    {
        x=1;
        y=0;
        return a; }
   d=exgcd(b,a%b,x,y);
   t=x;
   x=y;
   y=t-a/b*y;
   return d;
}
int main()
{
    __int64 a,b,x,y,ans;
    scanf("%I64d%I64d",&a,&b);
    ans=exgcd(a,b,x,y);
    printf("a*%I64d+b*%I64d=%I64d\n",x,y,ans);
}
