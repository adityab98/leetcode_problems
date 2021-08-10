def bestsum(n, arr, memo = {}):
    if (n in memo): return memo[n]
    if (n == 0): return []
    if (n < 0): return None
    shortest = None
    for x in arr:
        res = bestsum(n-x, arr, memo)
        if (res is not None):
            bruh = res.copy()
            bruh.append(x)
            if (shortest is None or len(bruh) < len(shortest)):
                shortest = bruh
    memo[n] = shortest
    return memo[n]

print(bestsum(7, [5, 3, 4, 7]))
print(bestsum(300, [7, 14]))
print(bestsum(100, [1, 2, 5, 25]))
print(bestsum(8, [1, 4, 5]))
