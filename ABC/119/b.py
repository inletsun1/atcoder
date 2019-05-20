N = int(input())
ans = 0
BtoJ = 380000
for _ in range(N):
    x, u = input().split()
    x = float(x)
    if u == 'JPY':
        ans += x
    else:
        ans += BtoJ * x

print(ans)
