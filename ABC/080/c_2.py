import itertools
N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]

cost = -10**7
a = (1, 1, 0, 1, 0, 0, 0, 1, 0, 1)
tmp_cost = 0
c = [0 for _ in range(N)]
for i in range(N):
    l = 0
    for j in range(5):
        for k in range(2):
            print("c[i] += " + str(F[i][l]) + "*" + str(a[l]))
            c[i] += F[i][l]*a[l]
            l += 1
    tmp_cost += P[i][c[i]]
if cost < tmp_cost:
    tmp_a = a
cost = max(cost, tmp_cost)
print(c)

print(cost)
