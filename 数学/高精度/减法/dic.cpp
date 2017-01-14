#include<bits/stdc++.h>
using namespace std;
string dic(string x, string y) /// Ìõ¼þ£º x >= y >= 0
{
    string a;
    int lx = x.size();
    int ly = y.size();
    int i,j;
    for(i=lx-1, j=ly-1; i>=0, j>=0; i--, j--)
    {
        if(x[i] < y[j])
        {
            x[i] = x[i]-y[j]+10+'0';
            x[i-1]--;
        }
        else
            x[i] = x[i]-y[j]+'0';
    }
    for(;i>=0; i--)
        if(x[i] < '0')
            x[i] += 10, x[i-1]--;
    for(i=0; x[i]=='0'; i++);
    return x.substr(i);
}
