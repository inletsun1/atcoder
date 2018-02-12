import numpy as np
N, M = map(int, input().split())
mat = np.zeros((N, N))
for i in range(M):
    a, b = map(int, input().split())
    mat[a-1][b-1] += 1
    mat[b-1][a-1] += 1

ans = np.sum(mat, axis=1)
for i in range(N):
    print(int(ans[i]))
