n = int(input())
T = 24*60//5+2
time = [0]*T
for i in range(n):
    s, e = input().split("-")
    s = (int(s[0:2])*60 + int(s[2:4]))//5
    e = (int(e[0:2])*60 + int(e[2:4]))//5
    time[s+1] = 1
    time[e+1] = -1

cumsum = [0]*(T-1)
cumsum = [time[i+1]+cumsum[i] for i in range(T-1)]

