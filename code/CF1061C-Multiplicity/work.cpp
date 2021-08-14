#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define MOD 1000000007

int n, a[100005];

void get_input() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
}

int dp[100005];

vector <int> fac;

void get_factor(int x) {    // 分解 x，因子放进 fac
    for(int i=1; i*i<=x; i++) {
        if(x%i == 0) {
            fac.push_back(i);

            if(x != i*i)
                fac.push_back(x / i);
        }
    }
    // 我们放进去的顺序：1, x, 2, x/2.... 无序状态

    sort(fac.begin(), fac.end(), greater<int>());
}

void calc_answer() {
    dp[0] = 1;          // 最开始，从0个里面选0个，方案数为1

    for(int x=1; x<=n; x++) {
        get_factor(a[x]);   // 因数放在了 fac

        for(auto y: fac)
            if(y <= x)
                dp[y] = (dp[y] + dp[y-1]) % MOD;

        fac.clear();
    }

    // 答案是 sum(dp[y])

    int ans = 0;
    for(int x=1; x<=n; x++)
        ans = (ans + dp[x]) % MOD;
    
    printf("%d\n", ans);
}

int main(void) {
    get_input();
    calc_answer();
    
    return 0;
}