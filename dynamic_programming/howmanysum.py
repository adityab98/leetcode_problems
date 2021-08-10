def howmanysum(n, arr, memo = {}):
    if (n == 0):
        return 1
    if (n < 0):
        return 0
    if (n in memo):
        return memo[n]
    else:
        memo[n] = 0
        for x in arr:
            memo[n] += howmanysum(n-x, arr, memo)
    return memo[n]

print(howmanysum(7, [5, 3, 4, 7]))
