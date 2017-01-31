#include<bits/stdc++.h>
using namespace std;
const int N = 110000+10;

char str[2*N];
int P[2*N], len, maxlen, id;

void Init()
{
    len = strlen(str);
    maxlen = id = 0;
    for(int i=len; i>=0; i--)
    {
        str[i+i+2] = str[i];
        str[i+i+1] = '#';
    }
    str[0] = '$';
    len = 2*len+1;
}

int Solve()
{
    for(int i=2; i<len; i++)
    {
        if(P[id]+id > i)
            P[i] = min(P[2*id-i], P[id]+id-i);
        else
            P[i] = 1;
        while(str[i-P[i]] == str[i+P[i]])
            ++P[i];
        if(id+P[id] < i+P[i])
            id = i;
        if(maxlen < P[i])
            maxlen = P[i];
    }
    return maxlen-1;
}

int main()
{
    while(~scanf("%s", str))
    {
        Init();
        printf("%d\n", Solve());
    }

    return 0;
}
