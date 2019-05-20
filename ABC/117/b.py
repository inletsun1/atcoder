N = int(input())
L = list(map(int, input().split()))

L.sort()

if(L[-1] < sum(L[0:-1])):
    print('Yes')
else:
    print('No')
