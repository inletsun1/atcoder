a, b, c = map(int, input().split())
i = 0 
while True:
    i += 1
    tmp = a%(2**i)
    if tmp!=0:
        a_n = i-1
        break

i = 1
while True:
    tmp = b%(2**i)
    if tmp!=0:
        b_n = i-1
        break
    i += 1

i = 1
while True:
    tmp = b%(2**i)
    if tmp!=0:
        c_n = i-1
        break
    i += 1

if(a==b==c):
    print(-1)
else:
    if(a_n == b_n):
        print(a_n+1)
    elif(b_n == c_n):
        print(b_n+1)
    elif(c_n == a_n):
        print(c_n+1)
    else:
        print(-1)

