from collections import defaultdict

S = input()
T = input()

d = defaultdict(lambda: '')
flag = True
for i in range(len(S)):
    if d[S[i]] == '' and d[T[i]] == '':
        d[S[i]] = T[i]
        d[T[i]] = S[i]
    elif d[S[i]] == T[i] and d[T[i]] == S[i]:
        pass
    else:
        flag = False
        break

print(d)

if flag:
    print("Yes")
else:
    print("No")
