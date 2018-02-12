#!/usr/bin/env python
N = int(input())
memo = [-1 for _ in range(N+1)]
def lucas(N):
    global memo
    if N==0:
        memo[0] = 2
        return 2
    if N==1:
        memo[1] = 1
        return 1
    if(memo[N]>0):
        return memo[N]
    else:
        memo[N] = lucas(N-1) + lucas(N-2)
        return memo[N]


print(lucas(N))
