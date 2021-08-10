def fib(n):
    arr = [0, 1]
    for i in range(2, n+1):
        arr.append(arr[i-1] + arr[i-2])
    return arr[n]

print(fib(8))
print(fib(3))
print(fib(0))
print(fib(150))
