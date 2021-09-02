# Python 3 program to find sum in the
# given range in the sequence 1 3 5 7
# .....N 2 4 6...N-1
import math

# For our convenience
#define ll long long

# Function that returns sum in the
# range 1 to x in the sequence
# 1 3 5 7.....N 2 4 6...N-1
def sumTillX(x, n):

	# number of odd numbers
	odd = math.ceil(n / 2.0)

	if (x <= odd):
		return x * x;

	# number of extra even
	# numbers required
	even = x - odd;

	return ((odd * odd) +
			(even * even) + even);


def rangeSum(N, L, R):

	return (sumTillX(R, N) -
				sumTillX(L-1, N));

# Driver code
N = 10
L = 1
R = 6
print(rangeSum(N, L, R))

# This code is contributed by
# Smitha
