#include <cstdio>
#include <algorithm>
using namespace std;

#define MOD 100000000

int n1, n2, k1, k2;

void get_input() {
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
}

int mem_dp[105][105][15][15];
bool visit_dp[105][105][15][15];

int calc_dp(int a, int b, int x, int y) {
    // printf("calc %d, %d, %d, %d\n", a, b, x, y);
    if(a + b <= 1)
        return 1;
    if(a < x || b < y)
        return 0;
    if(visit_dp[a][b][x][y])
        return mem_dp[a][b][x][y];
    visit_dp[a][b][x][y] = 1;
    
    int ans = 0;

    if(x == 0 && y == 1) {      // a, b, 0, 1
        for(int k=1; k<=min(k1, a); k++)
            ans = (ans + calc_dp(a, b-1, k, 0)) % MOD;
    } else if(x == 1 && y == 0) {   // a, b, 1, 0
        for(int k=1; k<=min(k2, b); k++)
            ans = (ans + calc_dp(a-1, b, 0, k)) % MOD;
    } else if(x > 1) {
        ans = calc_dp(a-1, b, x-1, y);
    } else if(y > 1) {
        ans = calc_dp(a, b-1, x, y-1);
    } else {
        puts("bug!");
    }

    // printf("calc dp(%d,%d,%d,%d) = %d\n", a, b, x, y, ans);

    mem_dp[a][b][x][y] = ans;
    return ans;
}

void calc_answer() {
    int ans = 0;

    for(int i=1; i<=k1; i++)
        ans = (ans + calc_dp(n1, n2, i, 0)) % MOD;
    for(int i=1; i<=k2; i++)
        ans = (ans + calc_dp(n1, n2, 0, i)) % MOD;
    
    printf("%d\n", ans);
}

int main(void) {
    get_input();
    calc_answer();
    
    return 0;
}