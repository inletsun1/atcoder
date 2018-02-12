from collections import defaultdict
N, K = map(int, input().split())
A = list(map(int, input().split()))
d = defaultdict(lambda :0)
for a in A:
    d[a] += 1
key_list = list(d.keys())
value_list = list(d.values())
value_list.sort()
tmp_num = len(value_list)

del_num = tmp_num - K
counter = 0
if del_num > 0:
    for v in value_list[0:del_num]:
        counter += v
print(counter)
