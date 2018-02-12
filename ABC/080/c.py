import itertools
N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]

cost = -10**10
for a in itertools.product((0, 1), repeat=10):
    if a==(0, 0, 0, 0, 0, 0, 0, 0, 0, 0):
        continue
    tmp_cost = 0
    for i in range(N):
        tmp_c = 0
        l = 0
        for j in range(5):
            for k in range(2):
                tmp_c += F[i][l]*a[l]
                l += 1
        tmp_cost += P[i][tmp_c]
    cost = max(cost, tmp_cost)

print(cost)
