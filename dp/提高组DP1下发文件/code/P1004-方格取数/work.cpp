#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int grid[15][15];

void get_input() {
    int x, y, v;

    scanf("%d", &n);

    while(scanf("%d%d%d", &x, &y, &v), x|y|v)
        grid[x][y] = v;
    
}

int dp[15][15][15][15];

void calc_dp() {
    for(int x=1; x<=n; x++)
        for(int y=1; y<=n; y++)
            for(int a=1; a<=n; a++)
                for(int b=1; b<=n; b++)
                    if(x+y == a+b) {
                        dp[x][y][a][b] = max(dp[x][y][a][b], dp[x-1][y][a-1][b]);
                        dp[x][y][a][b] = max(dp[x][y][a][b], dp[x-1][y][a][b-1]);
                        dp[x][y][a][b] = max(dp[x][y][a][b], dp[x][y-1][a-1][b]);
                        dp[x][y][a][b] = max(dp[x][y][a][b], dp[x][y-1][a][b-1]);

                        dp[x][y][a][b] += grid[x][y] + grid[a][b];
                        
                        if(x==a && y==b)
                            dp[x][y][a][b] -= grid[x][y];
                    }
}

int main(void) {
    get_input();
    calc_dp();

    printf("%d\n", dp[n][n][n][n]);

    return 0;
}
