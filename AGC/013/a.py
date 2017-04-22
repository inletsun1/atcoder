n = int(input())
a = list(map(int, input().split()))
del_a = [a[i+1]-a[i] for i in range(n-1)]
ans = 1
tmp = 0
before = del_a[0]
length = 1 
for i in range(1,n-1):
    tmp = del_a[i]
    if(before*tmp<0)and(length>1):
        length = 1
        ans += 1
    elif(before*tmp<0)and(i==n-2):
        ans+=1
    else:
        length += 1
    before = del_a[i]
print(ans)
