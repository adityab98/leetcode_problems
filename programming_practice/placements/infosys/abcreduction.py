s = input()
n = len(s)
count = [0]*3
for i in range(n):
    count[ord(s[i])-ord('a')] += 1

if (count[0] == n or count[1] == n or count[2] == n):
    print(n)
elif ((count[0] % 2) == (count[1] % 2) and (count[1] % 2) == (count[2] % 2)):
    print(2)
else: print(1)

#smallest string obtained by reducing string. can replace adjacent chars with the missing char. eg: bcab = (bc = a) and (ab = c) gives (ac) which gives (b)
