#!/usr/bin/env python
import collections
import itertools
N = int(input())
d = {'M':0, 'A':0, 'R':0, 'C':0, 'H':0}
for i in range(N):
    s = input()
    if s[0] in d:
        d[s[0]] += 1

ans = 0
for i in itertools.combinations(['M', 'A', 'R', 'C', 'H'], 3):
    ans = ans + d[i[0]]*d[i[1]]*d[i[2]]

print(ans)
