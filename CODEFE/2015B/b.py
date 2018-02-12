from collections import Counter
N, M = map(int, input().split())
A = list(map(int, input().split()))

A = Counter(A)
most = A.most_common(1)
most_num = most[0][1]
if most_num>=N//2+1:
    print(most[0][0])
else:
    print('?')
