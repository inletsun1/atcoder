N = int(input())
a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))

ans = 0
for i in range(1, N):
    a1[i] = a1[i-1] + a1[i]
    a2[N-i-1] = a2[N-i] + a2[N-i-1]

for i in range(N):
    ans = max(ans, a1[i] + a2[i])

print(ans)
