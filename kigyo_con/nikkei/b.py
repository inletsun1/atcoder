N = int(input())
A = input()
B = input()
C = input()

ans = 0
for i in range(N):
    if(A[i] == B[i] and B[i] == C[i]):
        continue
    elif(A[i] != B[i] and B[i] != C[i] and C[i] != A[i]):
        ans += 2
    else:
        ans += 1

print(ans)
