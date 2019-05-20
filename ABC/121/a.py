H, W = map(int, input().split())
h, w = map(int, input().split())

ans = h * W + H * w - h * w

print(H * W - ans)
