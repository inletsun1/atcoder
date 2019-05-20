S = input()
N = len(S)

ans = 0
before = 0
for i in range(N):
    tmp = S[i]
    if tmp == 'A' or tmp == 'T' or tmp=='C' or tmp == 'G':
        pass
    else:
        ans = max(i - before, ans)
        before = i + 1

ans = max(N - before, ans)
print(ans)
