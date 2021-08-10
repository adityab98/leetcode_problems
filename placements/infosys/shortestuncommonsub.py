# A simple recursive Python
# program to find shortest
# uncommon subsequence.
MAX = 1005

# A recursive function to
# find the length of shortest
# uncommon subsequence
def shortestSeq(S, T, m, n):

	# S String is empty
	if m == 0:
		return MAX

	# T String is empty
	if(n <= 0):
		return 1

	# Loop to search for
	# current character
	for k in range(n):
		if(T[k] == S[0]):
			break

	# char not found in T
	if(k == n):
		return 1

	# Return minimum of following
	# two Not including current
	# char in answer Including
	# current char
	return min(shortestSeq(S[1 : ], T, m - 1, n),
			1 + shortestSeq((S[1 : ]), T[k + 1 : ],
								m - 1, n - k - 1))

# Driver code
S = "babab"
T = "babba"

m = len(S)
n = len(T)
ans = shortestSeq(S, T, m, n)
if(ans >= MAX):
	ans =- 1
print("Length of shortest subsequence is:", ans)

# This code is contributed by avanitrachhadiya2155
