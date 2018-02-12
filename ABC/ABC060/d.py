N, W = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(N)]
w1 = wv[0][0]
memo = [[-1 for _ in range(W+1)] for _ in range(N)] 
memo[0][0] = 0
memo[0][w1] = wv[0][1]
def knapsack(i, j):
    if memo[i][j]>0:
        ans = memo[i][j]
    elif j<wv[i, 0]:
        ans = knapsack(i-1, j)
        memo[i][j] = ans
    else:
        ans = max([knapsack(i-1, j), knapsack(i-1, j-wv[i, 0])])
        memo[i][j] = ans
    return ans
print(knapsack(N, W))
#print(int(memo[N-1][W]))
