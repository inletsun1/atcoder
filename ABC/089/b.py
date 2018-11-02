#!/usr/bin/env python
import collections
N = int(input())
S = input().split()
c = collections.Counter(S)
if c['Y']>0:
    print('Four')
else:
    print('Three')
