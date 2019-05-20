N = int(input())

p = [int(input()) for _ in range(N)]

p.sort(reverse=True)

ans = p[0] // 2

for i in range(1, N):
    ans += p[i]

print(ans)
