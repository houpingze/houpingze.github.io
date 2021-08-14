#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int n, total;

void get_input() {
    char s[105];
    scanf("%s", s);

    total = 0;
    n = strlen(s);

    for(int p=0; s[p]; p++)
        total += s[p] - 'a' + 1;
}

int dp[105][3000];

void calc_answer() {
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;

    for(int k=1; k<=n; k++)
        for(int x=1; x<=total; x++) {
            long long res = 0;
            int tmp = min(26, x);
            
            for(int i=1; i<=tmp; i++)
                res += dp[k-1][x-i];
            dp[k][x] = res % MOD;
        }
            
    printf("%d\n", dp[n][total] - 1);
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        get_input();
        calc_answer();
    }

    return 0;
}