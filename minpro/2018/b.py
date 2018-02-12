X, K = map(int, input().split())
y = X+1

if y//(10**K) * 10**K > X:
    print(y//(10**K) * 10**K)
else:
    print(y//(10**K) * 10**K + 10**K)
