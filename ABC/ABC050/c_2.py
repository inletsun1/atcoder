import copy
n = int(input())
a = list(map(int, input().split()))
a.sort()
flag = True
if n % 2 == 1:
    if a[0] != 0:
        print(0)
    else:
        ans = [i for i in range(2, n, 2) for j in range(2)]
        ans.insert(0, 0)
        if ans != a:
            print(0)
            flag = False
    if flag:
        print((2**((n - 1) // 2)) % (10**9 + 7))

else:
    ans = [i for i in range(1, n, 2) for j in range(2)]
    if ans != a:
        print(0)
        flag = False
    if flag:
        print((2**(n // 2)) % (10**9 + 7))
