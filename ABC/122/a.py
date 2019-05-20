b = input()
ans = ''
for i in range(len(b)):
    tmp = b[i]
    if tmp == 'A':
        ans += 'T'
    elif tmp == 'T':
        ans += 'A'
    elif tmp == 'C':
        ans += 'G'
    elif tmp == 'G':
        ans += 'C'

print(ans)
