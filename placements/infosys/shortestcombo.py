# Python3 program to print supersequence of two strings

# Prints super sequence of a[0..m-1] and b[0..n-1]
def printSuperSeq(a, b):
	m = len(a)
	n = len(b)
	dp = [[0] * (n + 1) for i in range(m + 1)]

	# Fill table in bottom up manner
	for i in range(0, m + 1):
		for j in range(0, n + 1):
			
			# Below steps follow above recurrence
			if not i:
				dp[i][j] = j;
			elif not j:
				dp[i][j] = i;
			elif (a[i - 1] == b[j - 1]):
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else:
				dp[i][j] = 1 + min(dp[i - 1][j],
								dp[i][j - 1]);

	# Following code is used to print supersequence
	index = dp[m][n];

	# Create a string of size index+1
	# to store the result
	res = [""] * (index)

	# Start from the right-most-bottom-most corner
	# and one by one store characters in res[]
	i = m
	j = n;
	while (i > 0 and j > 0):
	
		# If current character in a[] and b are same,
		# then current character is part of LCS
		if (a[i - 1] == b[j - 1]):
		
			# Put current character in result
			res[index - 1] = a[i - 1];

			# reduce values of i, j and indexs
			i -= 1
			j -= 1
			index -= 1
		
		# If not same, then find the larger of two and
		# go in the direction of larger value
		elif (dp[i - 1][j] < dp[i][j - 1]):
			res[index - 1] = a[i - 1]
			i -= 1
			index -= 1

		else:
			res[index - 1] = b[j - 1]
			j -= 1
			index -= 1

	# Copy remaining characters of string 'a'
	while (i > 0):
		res[index - 1] = a[i - 1]
		i -= 1
		index -= 1

	# Copy remaining characters of string 'b'
	while (j > 0):
		res[index - 1] = b[j - 1]
		j -= 1
		index -= 1

	# Print the result
	print("".join(res))

# Driver Code
if __name__ == '__main__':
	a = "algorithm"
	b = "rhythm"
	printSuperSeq(a, b)
	
# This code is contributed by ashutosh450
