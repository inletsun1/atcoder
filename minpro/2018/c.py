import bisect
import copy
N = int(input())
x = list(map(int, input().split()))
c = list(map(int, input().split()))
v = list(map(int, input().split()))

memo = [[-1 for _ in range(N+1)] for _ in range(N+1)]
money = [[0 for _ in range(N+1)] for _ in range(N+1)]

buy_list = []
cv = [[c[i], v[i]] for i in range(N)]
sorted_cv = sorted(cv, key=lambda x:x[1], reverse=True)

print(sorted_cv[0])
cumsum_x = [0, x[0]]
for i in range(1, N):
    cumsum_x.append(cumsum_x[i-1] + x[i])

ans = 0
for i in range(0, N+1):
    for l in range(len(sorted_cv)):
        if sorted_cv[l][0] <= money[i][0]:
            del sorted_cv[l][0]

    for j in range(0, i+1):
        if i==0:
            memo[i][j] = 0
            money[i][j] = 0
        elif j==0:
            memo[i][j] = 0
            money[i][j] = cumsum_x[i]
        else:
            for k in range(len(sorted_cv)):
                if sorted_cv[k][0]<=money[i-1][j]:
                    tmp_c = sorted_cv[k][0]
                    tmp_v = sorted_cv[k][1]
                    flag = True
                    break
                else:
                    tmp_c = 10000000000000000
                    flag = False

            money1 = money[i][j-1] + x[j-1]
            money2 = money[i-1][j] - tmp_c
            if money2>=0 and memo[i][j-1] <= memo[i-1][j] + tmp_v:
                memo[i][j] = memo[i-1][j] + tmp_v
                money[i][j] = money2
            else:
                memo[i][j] = memo[i][j-1]
                money[i][j] = money1
        ans = max(ans, memo[i][j])

print(ans)
print(memo)
print(money)
