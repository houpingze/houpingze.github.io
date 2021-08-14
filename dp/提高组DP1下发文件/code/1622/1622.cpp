#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int dp[105][105];
int n, q, s[105];

void get_input() {
    scanf("%d%d", &n, &q);
    for(int i=1; i<=q; i++)
        scanf("%d", &s[i]);
    sort(s+1, s+1+q);
    s[q+1] = n+1;

    memset(dp, 0x3f, sizeof(dp));
}

int get_dp(int l, int r) {
    if(dp[l][r] != 0x3f3f3f3f)
        return dp[l][r];
    if(l > r)
        return 0;
    
    for(int k=l; k<=r; k++)
        dp[l][r] = min(dp[l][r], get_dp(l, k-1) + get_dp(k+1, r) + s[r+1] - s[l-1] - 2);

    return dp[l][r];
}

int main(void) {
    get_input();
    printf("%d\n", get_dp(1, q));

    return 0;
}