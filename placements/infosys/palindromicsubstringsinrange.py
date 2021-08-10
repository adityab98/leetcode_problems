# Python3 program to query the number of
# palindromic substrings of a string in a range
M = 50

# Utility method to construct the dp array
def constructDP(dp, string):

	l = len(string)

	# declare 2D array isPalin, isPalin[i][j]
	# will be 1 if str(i..j) is palindrome
	# and initialize it with zero
	isPalin = [[0 for i in range(l + 1)]
				for j in range(l + 1)]

	# loop for starting index of range
	for i in range(l - 1, -1, -1):

		# initialize value for one
		# character strings as 1
		isPalin[i][i], dp[i][i] = 1, 1

		# loop for ending index of range
		for j in range(i + 1, l):

			# isPalin[i][j] will be 1 if ith and jth
			# characters are equal and mid substring
			# str(i+1..j-1) is also a palindrome
			isPalin[i][j] = (string[i] == string[j] and
							(i + 1 > j - 1 or isPalin[i + 1][j - 1]))

			# dp[i][j] will be addition of number
			# of palindromes from i to j-1 and i+1
			# to j subtracting palindromes from i+1
			# to j-1 (as counted twice) plus 1 if
			# str(i..j) is also a palindrome
			dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] -
						dp[i + 1][j - 1] + isPalin[i][j])

# Method returns count of palindromic
# substring in range (l, r)
def countOfPalindromeInRange(dp, l, r):
	return dp[l][r]

# Driver code
if __name__ == "__main__":

	string = "xyaabax"
	dp = [[0 for i in range(M)]
			for j in range(M)]
	
	constructDP(dp, string)

	l, r = 3, 5
	print(countOfPalindromeInRange(dp, l, r))

# This code is contributed by Rituraj Jain
