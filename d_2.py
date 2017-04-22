import itertools
n, m = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

area = 0
r = 10**9+7
for xi in itertools.combinations(x,2):
    for yi in itertools.combinations(y,2):
        area = (area + (xi[1]-xi[0])*(yi[1]-yi[0]))%r

print(area)
