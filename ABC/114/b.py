S = input()
N = len(S)

ans = 10000
X = 100000
for i in range(0, N-2):
    tmp = int(S[i:i+3])
    if abs(ans - 753) > abs(tmp - 753):
        X = abs(tmp - 753)
        ans = tmp

print(X)
