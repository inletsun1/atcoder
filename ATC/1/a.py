import sys

sys.setrecursionlimit(1024*1024)
H, W = map(int, input().split())
C = []
for i in range(H):
    tmp = list(input())
    C.append(tmp)
    if 's' in tmp:
        s_w = tmp.index('s')
        s_h = i

WHITE = 0
GRAY = 1
BLACK = 2
dfs_color = [[WHITE for _ in range(W)] for _ in range(H)]
flag = False


def dfs(h, w):
    global dfs_color, flag
    dfs_color[h][w] = GRAY
    if C[h][w] == 'g' or flag:
        dfs_color[h][w] = BLACK
        flag = True
    for del_h in [-1, 1]:
        if 0 <= h + del_h <= H - 1 and C[h + del_h][w] != '#' and dfs_color[h + del_h][w] == WHITE and flag==False:
            dfs(h + del_h, w)
    for del_w in [-1, 1]:
        if 0<=w+del_w<=W-1 and C[h][w+del_w] != '#' and dfs_color[h][w+del_w]==WHITE and flag==False:
            dfs(h, w+del_w)

    dfs_color[h][w] = BLACK

dfs(s_h, s_w)
if flag:
    print('Yes')
else:
    print('No')
