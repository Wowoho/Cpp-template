#include<stdio.h>
#include<algorithm>
using namespace std;
int tree[100],a[100],n;
int lowbit(int x) {return x&(-x);}

int update(int x)
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j=j+lowbit(j))
            tree[j]=max(a[i],tree[j]);
}

int quriy(int l,int r)
{
    int ans=a[r];
    while(true){
          ans=max(ans,a[r]);
          if(r==l) break;
          for(r-=1;r-l>=lowbit(r);r-=lowbit(r)){
               ans=max(ans,tree[r]);
          }
     }
     return ans;
}
int main()
{
    int r,l;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    update(n);
    scanf("%d %d",&l,&r);
    printf("%d",quriy(l,r));
}

