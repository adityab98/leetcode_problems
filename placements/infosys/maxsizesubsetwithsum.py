# Python3 program to implement
# the above approach

# A Dynamic Programming solution
# for subset sum problem+ maximal
# subset value.
# Returns size of maximum sized subset
# if there is a subset of set[] with sun
# equal to given sum. It returns -1 if there
# is no subset with given sum.
def isSubsetSum(arr, n, sum):
	
	# The value of subset[i][j] will
	# be true if there is a subset of
	# set[0..j-1] with sum equal to i
	subset = [[False for x in range(n + 1)]
					for y in range (sum + 1)]
	count = [[0 for x in range (n + 1)]
				for y in range (sum + 1)]

	# If sum is 0, then answer is true
	for i in range (n + 1):
		subset[0][i] = True
		count[0][i] = 0
	
	# If sum is not 0 and set is empty,
	# then answer is false
	for i in range (1, sum + 1):
		subset[i][0] = False
		count[i][0] = -1
		

	# Fill the subset table in bottom up manner
	for i in range (1, sum + 1):
		for j in range (1, n + 1):
			subset[i][j] = subset[i][j - 1]
			count[i][j] = count[i][j - 1]
			if (i >= arr[j - 1]) :
				subset[i][j] = (subset[i][j] or
								subset[i - arr[j - 1]][j - 1])

				if (subset[i][j]):
					count[i][j] = (max(count[i][j - 1],
									count[i - arr[j - 1]][j - 1] + 1))
	return count[sum][n]

# Driver code
if __name__ == "__main__":

	arr = [2, 3, 5, 10]
	sum = 20
	n = 4
	print (isSubsetSum(arr, n, sum))

# This code is contributed by Chitranayal
