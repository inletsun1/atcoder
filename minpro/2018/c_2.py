import bisect
import copy
N = int(input())
x = list(map(int, input().split()))
c = list(map(int, input().split()))
v = list(map(int, input().split()))


cv = [[c[i], v[i]] for i in range(N)]
sorted_cv = sorted(cv, key=lambda x:x[1], reverse=True)
print(sorted_cv)

ans = 0
money = 0
for i in range(N):
    print("i=" + str(i))
    money += x[i]
    tmp_money = copy.deepcopy(money)
    print("tmp_money="+str(tmp_money))
    flag = True
    for l in range(len(sorted_cv)):
        print(sorted_cv[l])
        print(sorted_cv[l][0])
        if sorted_cv[l][0]<=money:
            del sorted_cv[l]
            flag = False
            break
    if flag:
        del sorted_cv[0]
    tmp_ans = 0
    for l in range(0, len(sorted_cv)):
        if sorted_cv[l][0] > money:
            break
        else:
            money -= sorted_cv[l][0]
            tmp_ans += sorted_cv[l][1]
    print("tmp_ans:" + str(tmp_ans)+" VS ans:" + str(ans))

    ans = max(ans, tmp_ans)

print(ans)
