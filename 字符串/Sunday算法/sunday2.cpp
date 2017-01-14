#include <iostream>
#include <cstring>
#include<stdio.h>
using namespace std;
#define array_size 26

int sunday(const char* ori, const char* patt)
{
    int len_s = strlen(ori);
    int len_d = strlen(patt);
    int jump[array_size] = {0};
    for (int j = 0; j < array_size; ++j)
        jump[j] = len_d + 1;
    for (int j = 0; j < len_d; ++j)
        jump[patt[j] - 'a'] = len_d - j; ///记录字符到最右段的最短距离+1
//例如:des = "abcedfb"
//next = {7 1 5 4 3 2 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8} </p><p>
    int pos = 0;
    int cnt = 0;
    while (pos < (len_s - len_d + 1)) //末端对齐
    {
        int i = pos;
        int j = 0;
        for (j = 0; j < len_d; ++j, ++i)
        {
            if (ori[i] != patt[j])
            {
                pos += jump[ori[pos + len_d] - 'a'];
                ///不等于就跳跃,跳跃是核心
                break;
            }
        }
        if (j == len_d)
            cnt++;
            ///return pos;
    }
    return cnt;
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
