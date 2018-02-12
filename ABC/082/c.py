from collections import defaultdict
d = defaultdict(lambda: 0)
N = int(input())
a = list(map(int, input().split()))
for tmp_a in a:
    d[tmp_a] += 1
key_list = list(d.keys())
key_list.sort()
counter = 0
for key in key_list:
    if d[key]>=key:
        counter += d[key]-key
    else:
        counter += d[key]

print(counter)
