N = int(input())
c = [0 for _ in range(N-1)]
s = [0 for _ in range(N-1)]
f = [0 for _ in range(N-1)]
for i in range(N-1):
    c[i], s[i], f[i] = map(int, input().split())

for (i, tmp_s) in enumerate(s):
    tmp_t = tmp_s 
    for j in range(i, N-1):
        if tmp_t<s[j]:
            delta = s[j] - tmp_t
        else:
            delta = f[j]-tmp_t%f[j]
        if delta==f[j]:
            delta = 0
        tmp_t = tmp_t + delta +c[j]
    print(tmp_t)

print(0)

