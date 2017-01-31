#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<queue>
using namespace std;

struct node
{
    int cnt;
    struct node *next[26];
    struct node *fail;
    void init()
    {
        for(int i=0; i<26; i++)
            next[i]=NULL;
        cnt=0;
        fail=NULL;
    }
}*root;
void add(char *str)
{
    int len,k;
    node *p=root;
    len=strlen(str);
    for(k=0; k<len; k++)
    {
        int pos=str[k]-'a';
        if(p->next[pos]==NULL)
        {
            p->next[pos]=new node;
            p->next[pos]->init();
            p=p->next[pos];
        }
        else
            p=p->next[pos];
    }
    p->cnt++;
}
void getfail()
{
    node *p=root,*son,*temp;
    queue<struct node *>que;
    que.push(p);
    while(!que.empty())
    {
        temp=que.front();
        que.pop();
        for(int i=0; i<26; i++)
        {
            son=temp->next[i];
            if(son!=NULL)
            {
                if(temp==root)
                {
                    son->fail=root;
                }
                else
                {
                    p=temp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            son->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(!p)  son->fail=root;
                }
                que.push(son);
            }
        }
    }
}
void query(char *str)
{
    int len, cnt=0;
    len=strlen(str);
    node *p,*temp;
    p=root;
    for(int i=0; i<len; i++)
    {
        int pos=str[i]-'a';
        while(!p->next[pos]&&p!=root)  p=p->fail;
        p=p->next[pos];//
        if(!p) p=root;//
        temp=p;
        /*��Ҫ��*temp=*p  ��Ϊ*p��ʾһ��node����*tempҲ��ʾһ��node ��������*tempû�з���ռ� �����ǲ��ܽ��и�ֵ�� ���ǿ�����tempָ��ȥָ��p*/
        while(temp!=root)
        {
            if(temp->cnt>=0)
            {
                cnt+=temp->cnt;
                temp->cnt=-1;
            }
            else break;
            temp=temp->fail;
        }
    }
    printf("%d\n",cnt);
}
int main()
{
    int T, n;
    char str[1000000+100];
    scanf("%d",&T);
    while(T--)
    {
        root=new node;
        root->init();
        root->fail=NULL;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%s", str);
            add(str);
        }
        getfail();
        scanf("%s", str);
        query(str);
    }
    return 0;
}
