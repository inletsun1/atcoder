from itertools import product as prd 
n, l, t = map(int, input().split())
x = [0]*n
w = [0]*n
xt = {}
#xt = [0]*n
ccw = []
cw = []
for i in range(n):
    x[i], w[i] = map(int, input().split())
    if w[i]==2:
        w[i] = -1
        ccw.append(i)
    else:
        cw.append(i)
    xt[i] = (x[i]+t*w[i])%l
d = {}
for tmp in prd(cw, ccw):
    if x[tmp[1]]<x[tmp[0]]:
        length = l+x[tmp[1]]-x[tmp[0]]
    else:
        length = x[tmp[1]]-x[tmp[0]]
    time = [i/10 for i in range(length*5, t*10+1, 40)]
    for i in range(len(time)):
        d[time[i]] = tmp
indxes = [i for i in range(n)]

for k in sorted(d.keys()):
    tmp = d[k]
    indxes[tmp[0]], indxes[1] = indxes[tmp[1]], indxes[tmp[0]]
    xt[indxes[0]], xt[indxes[1]] = xt[indxes[1]], xt[indxes[0]]
for k in sorted(xt.keys()):
    print(xt[k])
