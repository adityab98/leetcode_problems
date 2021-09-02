n = int(input())
s = input()
x = 1
depth = 0
while (n >= 0):
    n -= x
    x *= 2
    depth += 1
print(depth)
