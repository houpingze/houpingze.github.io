#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int A(int l,int r);
int B(int l,int r);

int a[1005]={0},s[1005]={0},n;

void init()
{
    int i;

    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    
}

int su(int l,int r)
{
    return s[r]-s[l-1];
}

int A(int l,int r)
{
    if(l==r) return a[l];
    if(dp[l][r]) return dp[l][r];
    dp[l][r]=max(B(l+1,r)+a[l],B(l,r-1)+a[r]);
    return dp[l][r];
}

int B(int l,int r)
{
    return su(l,r)-A(l,r);
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        init();
        printf("%d\n",A(1,n)-B(1,n));
    }
    
    
    return 0;
}