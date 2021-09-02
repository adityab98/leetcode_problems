# Python3 Program to print
# Hosoya's triangle of height n.
N = 5

# Print the Hosoya triangle
# of height n.
def printHosoya(n):
	dp = [[0 for i in range(N)]
			for i in range(N)]
			
	# base case.
	dp[0][0] = dp[1][0] = dp[1][1] = 1
	
	# For each row.
	for i in range(2, n):
		
		# for each column
		for j in range(n):
			
			# recursive steps.
			if (i > j):
				dp[i][j] = (dp[i - 1][j] +
							dp[i - 2][j])
			else:
				dp[i][j] = (dp[i - 1][j - 1] +
							dp[i - 2][j - 2])
							
	# printing the solution
	for i in range(n):
		for j in range(i + 1):
			print(dp[i][j], end = ' ')
		print()

# Driver Code
n = 5
printHosoya(n)

# This code is contributed
# by sahilshelangia
