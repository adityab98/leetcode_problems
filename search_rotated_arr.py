from typing import List
def search(nums: List[int], target: int) -> int:
    start = 0
    end = len(nums) - 1
    if (nums[0] > nums[-1]):
        while (start <= end):
            mid = (end + start) // 2
            if (nums[mid - 1] > nums[mid] and nums[mid + 1] > nums[mid]):
                start = mid
                break
            else:
                if (nums[mid] > nums[0]):
                    start = mid - 1
                else:
                    end = mid + 1
    nums = nums[start:] + nums[:start]
    diff = start
    start = 0
    end = len(nums) - 1
    while (start <= end):
        mid = (end - start) // 2
        if (nums[mid] == target):
            return (diff + mid) % len(nums)
        elif (nums[mid] > target):
            end = mid - 1
        else:
            start = mid + 1
    return -1

print(search([5,6,7,0,1,2,3,4], 5))
print(search([1,2,3,4,5,6,7], 5))
print(search([1,2,3,4,6,7], 5))
print(search([4,5,6,7,0,1,2], 0))
print(search([3, 1], 0))
