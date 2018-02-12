#!/usr/bin/env python
N, Z, W = map(int, input().split())
a = list(map(int, input().split()))
xy = [Z, W]
a_sorted = sorted(a)
tmp_ind = 0
teban = 0
enemy = 1
xory = 0
while(tmp_ind<N):
    if abs(a_sorted[0]-xy[enemy])>abs(a_sorted[-1]-xy[enemy]):
        xy[teban] = a_sorted[(0+xory)%2]
    else:
        xy[teban] = a_sorted[-((1+xory)%2)]

    new_ind = a[tmp_ind::].index(xy[teban]) + tmp_ind
    '''
    print('new_ind = ' + str(new_ind))
    print('a_sorted = ')
    print(a_sorted)
    '''
    for i in range(tmp_ind, new_ind+1):
        #print('remove of ' + str(a[i]))
        a_sorted.remove(a[i])
    #print(a_sorted)
    tmp_ind = new_ind+1
    teban, enemy = enemy, teban
    xory = (xory+1)%2

print(abs(xy[0]-xy[1]))
