#include<stdio.h>

int a[1000000];
int main()
{
    int n;
    //scanf("%d",&n);
    //while(n--)
   // {
        int m,b,i;
        scanf("%d",&m);
        scanf("%d",&a[1]);
        int l,r,mid,top;
        top=1;
        for(i=2;i<=m;i++)
        {
            scanf("%d",&b);
            if(b>a[top])
            {
                top++;
                a[top]=b;
            }
            else
            {
                l=1;
                r=top;
                while(l<=r)
                {
                    mid=(l+r)/2;
                    if(b>a[mid])
                        l=mid+1;
                    else
                        r=mid-1;
                }
                a[l]=b;
            }
        }
        printf("%d\n",top);
    //}
    return 0;
}
