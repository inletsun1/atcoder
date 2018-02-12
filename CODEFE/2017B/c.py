N, M = map(int, input().split())
C = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    C[a-1][b-1] = 1
    C[b-1][a-1] = 1

WHITE = 0
BLACK = WHITE + 1
color = [[WHITE for _ in range(N)] for _ in range(N)]

add_e = 0
def searchV(tmp_u, depth):
    global color, u, add_e
    if depth==3:
        if color[u][tmp_u] == WHITE and C[u][tmp_u] == 0 and tmp_u!=u:
            C[u][tmp_u] = 1
            C[tmp_u][u] = 1
            add_e += 1
            color[u][tmp_u] = BLACK
            color[tmp_u][u] = BLACK
            return
        else:
            return

    for tmp_v in range(N):
        if C[tmp_u][tmp_v]==1 and tmp_u!=tmp_v:
            searchV(tmp_v, depth+1)
        else:
            continue

for u in range(N):
    searchV(u, 0)

print(add_e)
