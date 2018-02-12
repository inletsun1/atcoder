import copy
s = list(input())

def search(s):
    raw_s = copy.deepcopy(s)
    tmp_str = '5'
    next_str = '2'
    del_ind = 0
    for i in range(0, len(s)):
        if s[i]==next_str:
            memo = next_str
            next_str = tmp_str
            tmp_str = memo
            del raw_s[i-del_ind]
            del_ind += 1
    return raw_s
            
if s[0]=='2' and s[-1]=='5' and len(s)%2==0:
    counter = 0
    while len(s)>0:
        s = search(s)
        counter += 1
    print(counter)
else:
    print(-1)
