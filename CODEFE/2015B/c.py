N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort(reverse=True)
B.sort(reverse=True)
flag = True
if len(A)<len(B):
    flag = False
else:
    for i in range(M):
        if A[i]>=B[i]:
            continue
        else:
            flag = False
            break

if flag:
    print('YES')
else:
    print('NO')
