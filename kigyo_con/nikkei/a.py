N, A, B = map(int, input().split())

print(str(min(A, B)) + " " + str(max(0, A + B - N)))
