from collections import Counter
N = int(input())
D = list(map(int, input().split()))
M = int(input())
T = list(map(int, input().split()))

D = Counter(D)
flag = True
for t in T:
    if D[t]>0:
        D[t] -= 1
    else:
        flag = False
        break
if flag:
    print('YES')
else:
    print('NO')
