#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1005], dp[1005][1005];

void get_input() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) 
        scanf("%d", &a[i]);
}

void calc_dp() {
    for(int k=1; k<=n; k++)
        for(int x=1; x<=k; x++)
            dp[k][x] = max(dp[k-1][x], dp[k-1][x-1] + (a[k] == x));
    
    int ans = 0;
    for(int i=1; i<=n; i++)
        ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
}

int main(void) {
    get_input();
    calc_dp();

    return 0;
}