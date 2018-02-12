import math
N, M = map(int, input().split())
kA = list(map(int, input().split()))
kB = list(map(int, input().split()))

memo = [[-1 for _ in range(M + 1)] for _ in range(sum(kA) + 1)]


def f(n, m):
    global memo
    print('n=' + str(n) + ' m=' + str(m))
    if memo[n][m] == -1:
        if n == 0 or 0 <= m <= 1:
            memo[n][m] = 1
            print(memo[n][m])
            return 1
        if n % 2 == 0:
            memo[n][m] = sum([f(i, m - 1) for i in range(0, n // 2 + 1)])
        else:
            memo[n][m] = sum([f(i, m - 1) for i in range(0, (n - 1) // 2 + 1)])
    print(memo[n][m])
    return memo[n][m]


dB = f(sum(kA), M)
print(dB)
memo = [[-1 for _ in range(N + 1)] for _ in range(sum(kB) + 1)]
dA = f(sum(kB), N)
print(dA)
print(memo)
print(dB + dA)
