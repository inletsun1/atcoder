A = int(input())
B = int(input())
C = int(input())
X = int(input())

counter = 0
for a in range(A+1):
    for b in range(B+1):
        c = X//50 - 10*a - 2*b
        if (0<=c<=C) and 500*a+100*b+50*c == X:
            counter += 1

print(counter)
