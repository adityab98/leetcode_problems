def howsum(n, arr, memo={}):
    if (n == 0):
        return []
    if (n < 0):
        return None
    if (n in memo):
        return memo[n]
    for x in arr:
        res = howsum(n-x, arr)
        if (res is not None):
            bruh = res.copy()
            bruh.append(x)
            memo[n] = bruh
            return memo[n]
    memo[n] = None
    return memo[n]

print(howsum(300, [7, 14]))
