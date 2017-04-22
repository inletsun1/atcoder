import itertools
n, m = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

s = [[(x[i+1]-x[i])*(y[j+1]-y[j]) for i in range(n-1) ]for j in range(m-1)]

#for i in itertools.combinations(s)

area = 0
r = 10**9+7
print(r)
for xi in itertools.combinations(x,2):
    for yi in itertools.combinations(y,2):
        area = (area + (xi[1]-xi[0])*(yi[1]-yi[0]))%r

print(area)
