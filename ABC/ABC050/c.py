import copy
n = int(input())
a = list(map(int, input().split()))
a.sort()
flag = True
if n % 2 == 1:
    if a[0] != 0:
        print(0)
    else:
        for i in range(2, n, 2):
            if not(a[i - 1] == i and a[i] == i):
                print(0)
                flag = False
                break
    if flag:
        print(int((2**((n-1)//2))%(1e9+7)))

else:
    for i in range(1, n, 2):
        if not(a[i - 1] == i and a[i] == i):
            print(0)
            flag = False
            break
    if flag:
        print(int((2**(n//2))%(1e9+7)))



