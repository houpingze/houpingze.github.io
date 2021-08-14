#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int round = 0;


void output_answer(bool ans) {
    printf("Collection #%d:\n", round);
    puts(ans ? "Can be divided.\n" : "Can't be divided.\n");
}

namespace knapsack {
    int n, max_weight;
    int weight[105];
    int dp[6000005];

    void init() {
        n = max_weight = 0;
        memset(weight, 0, sizeof(weight));
        memset(dp, 0, sizeof(dp));
    }

    void add_item(int w) {
        n++;
        weight[n] = w;
    }

    void solve() {
        dp[0] = 1;

        for(int k=1; k<=n; k++) {
            for(int w=max_weight; w>=weight[k]; w--)
                dp[w] |= dp[w - weight[k]];
        }

        output_answer(dp[max_weight]);
    }
}


void work() {
    int n[10], ball_cnt = 0, total_value = 0;

    round++;

    for(int i=1; i<=6; i++) {
        scanf("%d", &n[i]);
        ball_cnt += n[i];
        total_value += i * n[i];
    }

    if(ball_cnt == 0)
        exit(0);

    if(total_value % 2 == 1) {
        output_answer(false);
        return;
    }

    knapsack::max_weight = total_value / 2;

    for(int i=1; i<=6; i++) {
        int num = n[i];
        int weight = i;

        for(int k=1; k<=num; k*=2) {
            num -= k;
            knapsack::add_item(weight*k);
        }
        if(num)
            knapsack::add_item(weight*num);
    }

    knapsack::solve();
}

int main(void) {
    while(true) {
        knapsack::init();
        work();
    }

    return 0;
}