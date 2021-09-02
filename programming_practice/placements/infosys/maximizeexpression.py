a = int(input())
b = int(input())
"""
bina = bin(a)[2:]
binb = bin(b)[2:]
bina = bina[::-1]
binb = bina[::-1]

binc = ''
for i in range(len(binb)):
    if (binb[i] == '0'):
        binc+='0'
    else:
        if (bina[i] == '1'):
            binc += '0'
        else: binc += '1'

binc = binc[::-1]
print(int(binc, 2)^a)
"""
mx = 0
for i in range(b+1):
    if (b&i == i):
        if (a^i > mx):
            mx = a^i
print(mx)
