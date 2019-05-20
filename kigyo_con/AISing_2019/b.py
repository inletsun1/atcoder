N = int(input())
A, B = map(int, input().split())

p = list(map(int, input().split()))
p.sort()
a = 0
b = 0
c = 0
for tmp in p:
    if tmp <= A:
        a += 1
    elif A + 1 <= tmp <= B:
        b += 1
    else:
        c += 1

ans = min(a, b)
ans = min(ans, c)
print(ans)
