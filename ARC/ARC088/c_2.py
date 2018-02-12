#!/usr/bin/env python
import math 
X, Y = map(int, input().split())
n = Y//X 
ans = math.log2(n)
print("tmp_ans = " + str(ans))
ans = int(ans) + 1
print(ans)
