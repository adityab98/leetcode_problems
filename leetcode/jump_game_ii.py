# i = current position
def memoized_jumper(nums, i, memo=None):
    if (memo is None):
        memo = {}
    if (i in memo):
        return memo[i]
    if (i >= len(nums)-1):
        return 0
    min_jumps = 1000000001
    # go thru the max possible jump at current position
    for j in range(1, nums[i]+1):
        jumps = 1 + jumper(nums, i+j, memo)
        if (jumps < min_jumps):
            min_jumps = jumps
    memo[i] = min_jumps
    return min_jumps

def jump(nums):
    return jumper(nums, 0)

print(jump([2, 3, 1, 1, 4]))
print(jump([2, 3, 0, 1, 4]))
