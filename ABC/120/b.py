A, B, K = map(int, input().split())

i = min(A, B)
while K > 0:
    if A % i == 0 and B % i == 0:
        K -= 1
        ans = i
    i -= 1
print(ans)
