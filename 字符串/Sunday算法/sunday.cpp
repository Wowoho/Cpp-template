#include <iostream>
#include <cstring>
#include<stdio.h>
using namespace std;

int in_dst(const char word, const char *dst)
{
    int i = strlen(dst) - 1;

    while (dst[i] != '\0')
    {
        if (dst[i] == word)
          return (strlen(dst) - i);

        i--;
    }

    return -1;
}


int sunday(const char *src, const char *dst)
{
    int SrcLenth = strlen(src)+1, DstLenth = strlen(dst)+1;

    int j = 0, i = 0, pos;
    int ans = 0;
    while (j < SrcLenth)
    {
        i = 0;
        while (src[j+i] == dst [i])
        {
            i++;
            continue;
        }

        if (dst[i] == '\0')
        {
            ///printf("%d ~ %d\n", j, j+DstLenth-1);
            ans++;

        }

        if ((pos = in_dst(src[j+DstLenth], dst)) != -1)
        {
            j += pos;
        }
        else
        {
            j += (DstLenth + 1);
        }
    }
    return ans;
}


int main()
{
        char src[1000001];
        char des[100001];
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s%s",des,src);
            printf("%d\n",sunday(src,des));
        }

        return 0;
}
