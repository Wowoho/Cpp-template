#include<bits/stdc++.h>
using namespace std;
vector<int>fac;
vector<int>::iterator t;
int n;
int solve(int x)
{
    int i,num;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            fac.push_back(i);
            while(x%i==0)
                x/=i;
        }
    }
    if(x!=1)
    {
        fac.push_back(x);
    }
    num = fac.size();
    return num;
}
int main()
{
    scanf("%d",&n);
    printf("%d\n",solve(n));
    int k;
    for(t=fac.begin();t<fac.end();t++)
        printf("%d\n",*t);

    return 0;
}
