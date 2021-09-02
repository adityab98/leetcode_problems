# Python program to find
# maximum average cost path

# Maximum number of rows
# and/or columns
M = 100

# method returns maximum average of
# all path of cost matrix
def maxAverageOfPath(cost, N):
	
	dp = [[0 for i in range(N + 1)] for j in range(N + 1)]
	dp[0][0] = cost[0][0]

	# Initialize first column of total cost(dp) array
	for i in range(1, N):
		dp[i][0] = dp[i - 1][0] + cost[i][0]

	# Initialize first row of dp array
	for j in range(1, N):
		dp[0][j] = dp[0][j - 1] + cost[0][j]

	# Construct rest of the dp array
	for i in range(1, N):
		for j in range(1, N):
			dp[i][j] = max(dp[i - 1][j],
						dp[i][j - 1]) + cost[i][j]

	# divide maximum sum by constant path
	# length : (2N - 1) for getting average
	return dp[N - 1][N - 1] / (2 * N - 1)

# Driver program to test above function
cost = [[1, 2, 3],
		[6, 5, 4],
		[7, 3, 9]]

print(maxAverageOfPath(cost, 3))

# This code is contributed by Soumen Ghosh.
