S = input()
ans = 'keyence'

if(len(S) == 7 and ans==S):
    print('YES')
else:
    for i in range(7):
        if(S[i] == ans[i]):
            flag = True
        elif S[len(S)-7+i::] == ans[i::]:
            flag = True
            break
        else:
            flag = False
            break

    if(~flag):
        ans = ans[::-1]
        S = S[::-1]
        for i in range(7):
            if(S[i] == ans[i]):
                flag = True
            elif S[len(S)-7+i::] == ans[i::]:
                flag = True
                break
            else:
                flag = False
                break

    

    if(flag):
        print('YES')
    else:
        print('NO')
