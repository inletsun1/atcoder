import copy
n = int(input())
a = list(map(int, input().split()))

def judge_pm(a,b):
    if a*b<0:
        return True
    else:
        return False

a1 = copy.deepcopy(a)
operate_num1 = 0
if a1[0]==0:
    a1[0] = 1
    operate_num1 += 1
tmp_sum = a1[0]
for i in range(1, n):
    if judge_pm(tmp_sum, tmp_sum+a1[i]):
        pass 
    elif tmp_sum<0:
        tmp_operate_num =  - tmp_sum + 1 - a1[i]
        operate_num1 += tmp_operate_num
        a1[i] += tmp_operate_num
    else:
        tmp_operate_num = tmp_sum + 1 + a1[i]
        operate_num1 += tmp_operate_num
        a1[i] -= tmp_operate_num
    tmp_sum += a1[i]
        
a2 = copy.deepcopy(a)
operate_num2 = 0
if a2[0]<0:
    operate_num2 += 1 - a2[0]
    a2[0] += operate_num2
else:
    operate_num2 += a2[0] + 1
    a2[0] -= operate_num2

tmp_sum = a2[0]

for i in range(1, n):
    if judge_pm(tmp_sum, tmp_sum+a2[i]):
        pass 
    elif tmp_sum<0:
        tmp_operate_num =  - tmp_sum + 1 - a2[i]
        operate_num2 += tmp_operate_num
        a2[i] += tmp_operate_num
    else:
        tmp_operate_num = tmp_sum + 1 + a2[i]
        operate_num2 += tmp_operate_num
        a2[i] -= tmp_operate_num
    tmp_sum += a2[i]

print(min(operate_num1, operate_num2))        
