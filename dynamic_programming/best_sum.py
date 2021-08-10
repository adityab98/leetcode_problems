# m = target, n = len(numbers)
# O(mmn) time & O(mm) space
def best_sum(target, numbers):
    table = [None] * (target+1)
    table[0] = []
    for i in range(target+1):
        if (table[i] is None): continue
        for num in numbers:
            if (i+num <= target):
                temp_sum = table[i].copy()
                temp_sum.append(num)
                if (table[i+num] is None 
                        or len(temp_sum) < len(table[i+num])):
                    table[i+num] = temp_sum
    return table[target]

print(best_sum(7, [5, 3, 4]))
print(best_sum(7, [2, 3]))
print(best_sum(7, [2, 4]))
print(best_sum(8, [2, 3, 5]))
print(best_sum(100, [25, 2, 5, 1]))
print(best_sum(300, [7, 14]))
