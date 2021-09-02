n = int(input())
arr = [1]
c2 = c3 = c5 = 0
while (len(arr) < n):
    next = min(2*arr[c2], 3*arr[c3], 5*arr[c5])
    arr.append(next)
    if (next == 2*arr[c2]): c2 += 1
    if (next == 3*arr[c3]): c3 += 1
    if (next == 5*arr[c5]): c5 += 1

print(arr[n-1])
