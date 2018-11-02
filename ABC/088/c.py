c = [list(map(int, input().split())) for _ in range(3)]

flag = True
for i in range(1, 3):
    tmp_del = c[i][0] - c[i-1][0]
    for j in range(1, 3):
        if c[i-1][j]+tmp_del==c[i][j]:
            continue
        else:
            flag = False
            break

if flag:
    print('Yes')
else:
    print('No')
