n = int(input())
a = list(map(int, input().split()))
ans = 1
def incr(a,b):
    if a>b:
        return -1
    elif a==b:
        return 0
    else:
        return 1
init = incr(a[0], a[1])
flag = True
for i in range(1, n-1):
    tmp = incr(a[i], a[i+1])
    #print("a[i]=", a[i]," a[i+1]=", a[i+1], " init=", init, " tmp=", tmp)
    if tmp==0:
        tmp = init
    if init*tmp<0 and flag:
        ans += 1
        init = tmp
        flag = False
        #print(i)
        continue
    init = tmp
    flag = True
print(ans)
