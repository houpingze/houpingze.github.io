#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

namespace knapsack {
    int n, max_weight;
    int weight[2005], value[2005];
    int dp[40005];

    void add_item(int w, int v) {
        n++;
        weight[n] = w;
        value[n] = v;
    }

    int solve() {
        for(int k=1; k<=n; k++)
            for(int w=max_weight; w>=weight[k]; w--)
                dp[w] = max(dp[w], dp[w-weight[k]] + value[k]);
        
        int ans = 0;
        for(int w=0; w<=max_weight; w++)
            ans = max(ans, dp[w]);
        return ans;
    }
}

void get_input() {
    int n, W;
    scanf("%d%d", &n, &W);

    knapsack::max_weight = W;

    while(n--) {
        int value, weight, num;
        scanf("%d%d%d", &value, &weight, &num);

        for(int k=1; k<=num; k*=2) {
            num -= k;
            knapsack::add_item(weight*k, value*k);
        }
        if(num)
            knapsack::add_item(weight*num, value*num);
    }
}

int main(void) {
    get_input();
    printf("%d\n", knapsack::solve());

    return 0;
}