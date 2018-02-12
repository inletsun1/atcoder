N = int(input())
masu = [0 for _ in range(10**5)]
for _ in range(N):
    s, c = map(int, input().split())
    goal = s - 1
    counter = 0
    i = s-1
    while (i<=10**5-1):
        #print('tmp = ' + str(i+1))
        #print('counter = ' + str(counter))
        #print('')
        if masu[i]==0:
            counter += 1
            masu[i] = 1
            goal += 1
            i += 1
        else:
            i += 1
            goal += 1
        if counter==c:
            break
    print(goal)
