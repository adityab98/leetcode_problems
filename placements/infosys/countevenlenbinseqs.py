# A Python program to count
# even length binary sequences
# such that the sum of first
# and second half bits is same

# Returns the count of
# even length sequences
def countSeq(n):

	nCr = 1
	res = 1

	# Calculate SUM ((nCr)^2)
	for r in range(1, n + 1):
	
		# Compute nCr using nC(r-1)
		# nCr/nC(r-1) = (n+1-r)/r;
		nCr = (nCr * (n + 1 - r)) / r;

		res += nCr * nCr;

	return res;

# Driver Code
n = 2
print("Count of sequences is"),
print (int(countSeq(n)))
	
# This code is contributed
# by Shivi_Aggarwal
