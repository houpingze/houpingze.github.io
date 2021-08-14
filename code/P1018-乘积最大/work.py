n, k = map(int, input().split())
k += 1

a = input()

dp = [[0 for x in range(k+1)] for y in range(n+1)]
dp[0][0] = 1

for pos in range(1, n+1):
    for x in range(1, k+1):
        for i in range(pos):
            dp[pos][x] = max(dp[pos][x], dp[i][x-1] * int(a[i:pos]))

print(dp[n][k])