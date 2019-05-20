N = list(map(int, input().split()))
ans = [1, 4, 7, 9]
N.sort()
flag = True
for i in range(4):
    if(ans[i] == N[i]):
        continue
    else:
        flag = False
        break

if(flag):
    print('YES')
else:
    print('NO')
