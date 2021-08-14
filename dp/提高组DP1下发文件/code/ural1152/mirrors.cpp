#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, num_monster[25], total_monster;

void get_input() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &num_monster[i]);
        total_monster += num_monster[i];
    }
}

int bitmask[25];
int dp[(1<<20) + 5];

void init() {
    for(int i=0; i<n; i++) {
        for(int pos=0; pos<3; pos++)
            bitmask[i] |= (1<<((pos + i) % n));
    }

    memset(dp, -1, sizeof(dp));
}

int calc_dp(int state) {
    // printf("call dp(%x)\n", state);
    if(dp[state] != -1)
        return dp[state];
    if(state == (1<<n) - 1) {
        return 0;
    }

    int round_cost = 0, min_cost = 0x3f3f3f3f;

    for(int i=0; i<n; i++)
        if(((state >> i) & 1) == 0)
            round_cost += num_monster[i];

    for(int i=0; i<n; i++)
        if((state & bitmask[i]) != bitmask[i])
            min_cost = min(min_cost, calc_dp(state | bitmask[i]));
    
    dp[state] = round_cost + min_cost;
    return dp[state];
}

int main(void) {
    get_input();
    init();
    printf("%d\n", calc_dp(0) - total_monster);
    
    return 0;
}