import numpy as np
N, M = map(int, input().split())
mat = np.zeros((N, N))
for i in range(M):
    a, b, c = map(int, input().split())
    mat[a-1,b-1] = c
score = 0
tmp_v = 1
ever_v = [1]
while True:
    next_v = np.argmax(mat[tmp_v-1,:]) + 1
    score += mat[tmp_v-1,next_v-1]
    if next_v in ever_v:
        print('inf')
        break
    if next_v==N:
        print(score)
        break
    tmp_v = next_v

