from collections import defaultdict
N, K = map(int, input().split())
seq = defaultdict(lambda: 0) 
for i in range(N):
    a, b = map(int, input().split())
    seq[a] += b

values = list(seq.keys())

values.sort()
ans = 0
for i in range(len(values)):
    K -= seq[values[i]]
    if(K<=0):
        print(values[i])
        break

