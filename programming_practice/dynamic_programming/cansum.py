def cansum(n, arr, memo = {}):
    if (n == 0):
        return True
    if (n < 0):
        return False
    if (n in memo):
        return memo[n]
    else:
        for x in arr:
            if (cansum(n-x, arr)):
                memo[n] = True
                return memo[n]
    memo[n] = False
    return memo[n]

print(cansum(300, [11]))
