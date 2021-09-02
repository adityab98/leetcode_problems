# Python3 program to count increasing
# subsequences in an array of digits.

# Function To Count all the sub-
# sequences possible in which digit
# is greater than all previous digits
# arr[] is array of n digits
def countSub(arr, n):

	# count[] array is used to store all
	# sub-sequences possible using that
	# digit count[] array covers all the
	# digit from 0 to 9
	count = [0 for i in range(10)]

	# scan each digit in arr[]
	for i in range(n):
	
		# count all possible sub-sequences by
		# the digits less than arr[i] digit
		for j in range(arr[i] - 1, -1, -1):
			count[arr[i]] += count[j]

		# store sum of all sub-sequences
		# plus 1 in count[] array
		count[arr[i]] += 1
	

	# Now sum up the all sequences
	# possible in count[] array
	result = 0
	for i in range(10):
		result += count[i]

	return result

# Driver Code
arr = [3, 2, 4, 5, 4]
n = len(arr)
print(countSub(arr, n))

# This code is contributed by Anant Agarwal.
