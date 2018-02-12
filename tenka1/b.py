N = int(input())
a = []
b = []


for i in range(N):
    tmp_a, tmp_b = map(int, input().split())
    a.append(tmp_a)
    b.append(tmp_b)

ans = max(a)
max_ind = a.index(ans)
ans += b[max_ind]
print(ans)
