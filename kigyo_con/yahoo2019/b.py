A = [[0 for _ in range(4)] for _ in range(4)]


for _ in range(3):
    a, b = map(int, input().split())
    A[a-1][b-1] = 1
    A[b-1][a-1] = 1

B = [sum(A[i]) for i in range(4)]

for i in range(4):
    if B[i] == 3 or B[i] == 0:
        flag = False
        break
    else:
        flag = True

if flag:
    print('YES')
else:
    print('NO')
