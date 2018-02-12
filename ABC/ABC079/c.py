#!/usr/bin/env python
import itertools
input_str = input()
A = input_str[0]
B = input_str[1]
C = input_str[2]
D = input_str[3]

ops = ['+', '-']
all_ops = list(itertools.product(A, ops, B, ops, C, ops, D))
for tmp in all_ops:
    result = eval(''.join(tmp))
    if result == 7:
        print(''.join(tmp) + "=7")
        break
