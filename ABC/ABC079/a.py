#!/usr/bin/env python
N = input()
tmp = N[0]
counter = 1
flag = False
for i in range(1,len(N)):
    if N[i]==tmp:
        counter += 1
    else:
        tmp = N[i]
        counter = 1
    if counter==3:
        flag = True
        break

if flag:
    print("Yes")
else:
    print("No")
