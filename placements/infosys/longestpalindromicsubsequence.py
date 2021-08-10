s = input()

def lps(s, i, j):
    if (i == j):
        return 1
    if (s[i] == s[j] and i+1==j):
        return 2
    if (s[i] == s[j]):
        return lps(s, i+1, j-1) + 2
    return max(lps(s, i, j-1), lps(s, i+1, j))
        
print(lps(s, 0, len(s)-1))
