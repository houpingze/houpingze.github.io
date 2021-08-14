#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, c0, d0;
int a[15], b[15], c[15], d[15];

void get_input() {
    scanf("%d%d%d%d", &n, &m, &c0, &d0);
    for(int i=1; i<=m; i++)
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
}

int dp[15][1005];

void calc_dp() {
    for(int k=1; k<=m; k++)
        for(int r=0; r<=n; r++)
            for(int i=0; i*b[k]<=a[k] && i*c[k]<=r; i++)
                dp[k][r] = max(dp[k][r], dp[k-1][r-i*c[k]] + i*d[k]);
    
    int ans = 0;

    for(int r=0; r<=n; r++) {
        // printf("%d\n", dp[m][r] + (n-r)/c0*d0);
        ans = max(ans, dp[m][r] + (n-r)/c0*d0);
    }

    printf("%d\n", ans);
}

int main(void) {
    get_input();
    calc_dp();

    return 0;
}