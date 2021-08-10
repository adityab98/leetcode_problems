def substrings(s):
    substrs = []
    for i in range(len(s)):
        for ln in range(i+1, len(s)+1):
            substrs.append(s[i:ln])
    return substrs
    
s = input()
subs = substrings(s)
vowels = ['A', 'E', 'I', 'O', 'U']
ramu = 0
abhi = 0
for sub in subs:
    if (sub[0] in vowels):
        ramu += 1
    else:
        abhi += 1

if (abhi > ramu):
    print("Abhi " + str(abhi))
else:
    print("Ramu " + str(ramu))
