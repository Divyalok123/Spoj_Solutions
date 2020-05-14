p = int(input())

for _ in range(p):
    n, k, m = map(int, input().strip().split())
    n = n*k
    t = 0
    while (n <= m):
        n = n*k
        t += 1
    print(t)