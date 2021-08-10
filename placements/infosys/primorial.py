# Python3 program to find Primorial of given numbers
import math
MAX = 1000000;

# vector to store all prime less than and equal to 10^6
primes=[];

# Function for sieve of sundaram. This function stores all
# prime numbers less than MAX in primes
def sieveSundaram():

	# In general Sieve of Sundaram, produces primes smaller
	# than (2*x + 2) for a number given number x. Since
	# we want primes smaller than MAX, we reduce MAX to half
	# This array is used to separate numbers of the form
	# i+j+2ij from others where 1 <= i <= j
	marked=[False]*(int(MAX/2)+1);

	# Main logic of Sundaram. Mark all numbers which
	# do not generate prime number by doing 2*i+1
	for i in range(1,int((math.sqrt(MAX)-1)/2)+1):
		for j in range(((i*(i+1))<<1),(int(MAX/2)+1),(2*i+1)):
			marked[j] = True;

	# Since 2 is a prime number
	primes.append(2);

	# Print other primes. Remaining primes are of the
	# form 2*i + 1 such that marked[i] is false.
	for i in range(1,int(MAX/2)):
		if (marked[i] == False):
			primes.append(2*i + 1);

# Function to calculate primorial of n
def calculatePrimorial(n):
	# Multiply first n primes
	result = 1;
	for i in range(n):
		result = result * primes[i];
	return result;

# Driver code
n = 5;
sieveSundaram();
for i in range(1,n+1):
	print("Primorial(P#) of",i,"is",calculatePrimorial(i));

# This code is contributed by mits
