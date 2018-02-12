#!/usr/bin/env python

X, Y = map(int, input().split())
n = Y//X 

def num_division(n):
    num = 0
    for i in range(2, int(n**0.5 + 1e-9) + 1):
        if n%i == 0:
            num += 1
            if n!=i**2:
                num += 1
    return num

def main():
    global X, Y, n
    tmp_ans = 1
    for i in range(X, Y + 1):
        tmp_ans = max(tmp_ans, num_division(n)+1)
    return tmp_ans

print(main())
#print(n)
