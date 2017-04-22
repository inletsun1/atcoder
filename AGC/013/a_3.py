n = int(input())
a = list(map(int, input().split()))
ans = 1
incr = None
for i, x in enumerate(a):
    if i==0:
        before = x
        continue
    if incr==None:
        if x > before:
            incr = 1
        elif x < before:
            incr = -1
        before = x
        continue
    if (incr==1)and(x < before):
        ans += 1
        incr = None
    elif (incr==-1)and(x > before):
        ans += 1
        incr = None
    before = x    
print(ans)
