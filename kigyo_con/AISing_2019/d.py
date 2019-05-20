import bisect

N, Q = map(int, input().split())

A = list(map(int, input().split()))

A.sort()

ansers = []
for i in range(Q):
    ans = 0
    X = int(input())
    near_X = bisect.bisect_left(A, X)
    a = A[0:near_X]
    b = A[near_X:N]
    while((len(a) > 0) or (len(b) > 0)):
        if len(b) > 0:
            ans += b[-1]
            b.pop(-1)
        else:
            ans += a[-1]
            a.pop(-1)

        if(len(a) <= 0 and len(b) <= 0):
            break

        if len(b) > 0:
            if len(a) > 0 and X - a[-1] <= b[-1] - X:
                a.pop(-1)
            else:
                b.pop(0)
        else:
            a.pop(-1)

    ansers.append(ans)

for i in range(Q):
    print(ansers[i])

