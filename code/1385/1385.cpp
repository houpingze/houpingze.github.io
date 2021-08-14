#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int n, total;

void get_input() {
    char s[105];
    fgets(s, 103, stdin);

    total = 0;

    for(n=0; s[n] >= 'a'; n++)
        total += s[n] - 'a' + 1;
}

int dp[105][2605];

void calc_answer() {
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;

    for(int k=1; k<=n; k++)
        for(int x=1; x<=total; x++) {
            int tmp = 26 < x ? 26 : x;
            long long res = 0;

            
            int *arr_begin = &dp[k-1][x-tmp];
            int *arr_end = &dp[k-1][x-1];

            for(int *p=arr_begin; p<=arr_end; p++)
                res += *p;
            
            dp[k][x] = res % MOD;
        }

    printf("%d\n", dp[n][total] - 1);
}

int main(void) {
    int T;
    scanf("%d\n", &T);

    while(T--) {
        get_input();
        calc_answer();
    }

    return 0;
}