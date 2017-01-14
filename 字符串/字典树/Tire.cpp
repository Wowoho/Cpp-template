#include<bits/stdc++.h>
using namespace std;

struct node
{
    node * next[26];
    bool word;
    node()
    {
        word=false;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} root;

void buildTrie(char *str)
{
    node * p = &root;
    for(int i = 0; str[i] ;i++)
    {
        int t = str[i] - 'a';
        if(p -> next[t] == NULL)
            p -> next[t] = new node;
        p = p -> next[t];
    }
    p -> word = true;
}

bool findTrie(char str[])
{
    node * p = &root;
    for(int i = 0; str[i] ;i++)
    {
        int t = str[i] - 'a';
        if(p -> next[t] == NULL)
            return false;
        p = p -> next[t];
    }
    return p -> word;
}

int main()
{
    int n;
    char c[100];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",c);
        buildTrie(c);
    }

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",c);
        if(findTrie(c))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
