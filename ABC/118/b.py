N , M = map(int, input().split())

a = [0 for _ in range(M)]

for _ in range(N):
    A = list(map(int, input().split()))
    A.pop(0)
    for i in range(len(A)):
        a[A[i]-1] += 1

ans = 0
for i in range(M):
    if a[i] == N:
        ans += 1
print(ans)
