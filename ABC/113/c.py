from collections import defaultdict

N, M = map(int, input().split())
yp = []
d = defaultdict(lambda: [])
ans = ['' for _ in range(M)]
for i in range(M):
    p, y = input().split()
    d[int(p)].append([i, int(y)])


for key in d.keys():
    d[key].sort(key = lambda x : x[1])
    num = 1
    for i in range(len(d[key])):
        ans[d[key][i][0]] += '{:0=6}'.format(key) \
                + '{:0=6}'.format(num) 
        #print('city: ' + str(d[key][i][0]) + ', prefecture: ' + str(key) + ', n-th:', str(i + 1))
        num += 1

for i in range(M):
    print(ans[i])
