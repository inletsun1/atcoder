o = input()
e = input()
s = ""
n = max([len(o),len(e)])

for i in range(n):
    s += o[i]
    if i<=len(e)-1:
        s += e[i]

print(s)
