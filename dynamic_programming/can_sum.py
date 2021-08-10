# m = target, n = len(numbers)
# O(mn) time & O(m) space
def can_sum(target, numbers):
    arr = [False]*(target+1)
    arr[0] = True
    for i in range(target+1):
        if not arr[i]:
            continue
        for number in numbers:
            if (i+number <= target):
                arr[i+number] = True
    return arr[target]

print(can_sum(7, [5, 3, 4]))
print(can_sum(7, [2, 3]))
print(can_sum(7, [2, 4]))
print(can_sum(8, [2, 3, 5]))
print(can_sum(300, [7, 14]))
