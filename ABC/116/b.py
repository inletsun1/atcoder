import bisect
s = int(input())

a = [s]
b = [s]
def f(n):
    if(n % 2 == 0):
        return n/2
    else:
        return 3 * n + 1
n = 1
while(True):
    tmp = f(a[n-1])
    insert_index = bisect.bisect_left(b, tmp)
    if len(b) > insert_index and b[insert_index] == tmp:
        ans = n + 1
        break
    else:
        if len(b) == insert_index:
            b.append(tmp)
        else:
            b.insert(insert_index, tmp)
        a.append(tmp)
    n += 1

print(ans)
