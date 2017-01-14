#include<bits/stdc++.h>
using namespace std;
vector<int>id;
int main()
{
    int n;
    int num[1000];
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
       cin >> num[i];
       id.push_back(num[i]);
    }

    sort(id.begin(), id.end());

    id.erase(unique(id.begin(), id.end()) , id.end());
    //去重让每一个值都是单一的

    for(int i = 0;i < n;i ++)
        num[i] = lower_bound(id.begin(), id.end(), num[i]) - id.begin() + 1;
    //把值改变成编号，映射回来的方法 id[num[i] - 1];

    for(int i = 0;i < n;i ++)
        cout<< num[i] <<" ";
    return 0;
}
