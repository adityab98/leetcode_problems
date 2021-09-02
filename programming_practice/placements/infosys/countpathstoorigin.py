# Python3 program to count total
# number of paths from a po to origin

# Recursive function to count
# number of paths
def countPaths(n, m):

	# If we reach bottom or top
	# left, we are have only one
	# way to reach (0, 0)
	if (n == 0 or m == 0):
		return 1

	# Else count sum of both ways
	return (countPaths(n - 1, m) +
			countPaths(n, m - 1))

# Driver Code
n = 3
m = 2
print("Number of Paths",
	countPaths(n, m))

# This code is contributed by ash264
