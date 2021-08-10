# m = target, n = len(numbers)
# O(mmn) time & O(mm) space
def how_sum(target, numbers):
    table = [None] * (target+1)
    table[0] = []
    for i in range(target+1):
        if (table[i] is None): continue
        for num in numbers:
            if (i+num <= target):
                table[i+num] = table[i].copy()
                table[i+num].append(num)
    return table[target]

print(how_sum(7, [5, 3, 4]))
print(how_sum(7, [2, 3]))
print(how_sum(7, [2, 4]))
print(how_sum(8, [2, 3, 5]))
print(how_sum(300, [7, 14]))
