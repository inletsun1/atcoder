N, K = map(int, input().split())

if (N % 2 == 0 and N // 2 >= K) or (N % 2 == 1 and (N + 1) // 2 >= K):
    print('YES')
else:
    print('NO')
