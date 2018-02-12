S = list(input())
T = input()

flag = True
tmp_ind = len(T)-1
for i in range(len(S)-1, -1, -1):
    if(S[i]=='?' or S[i]==T[tmp_ind]) and flag:
        if tmp_ind==0:
            s_ind = i
            flag = False
            break
        tmp_ind -= 1
    else:
        tmp_ind = len(T)-1

if flag:
    print('UNRESTORABLE')
else:
    j = 0
    for i in range(s_ind, s_ind+len(T)):
        S[i] = T[j]
        j += 1
    for i in range(len(S)):
        if S[i]=='?':
            S[i] = 'a'
    print("".join(S))
