def countOccurances(n: str) -> str:
    res = ''
    curr = 1
    for i in range(len(n)):
        if (i+1 < len(n) and n[i] == n[i+1]):
            curr += 1
        else:
            res += str(curr) + n[i]
            curr = 1
    return res


def countAndSay(n: int, memo=None) -> str:
    if (memo is None):
        memo = {}
    if (n in memo):
        return memo[n]
    if (n == 1):
        return "1"
    if (n == 2):
        return "11"
    expr = countAndSay(n-1, memo)
    memo[n] = countOccurances(expr)
    return memo[n]


print(countAndSay(1))
print(countAndSay(2))
print(countAndSay(3))
print(countAndSay(4))
print(countAndSay(5))
print(countAndSay(6))
