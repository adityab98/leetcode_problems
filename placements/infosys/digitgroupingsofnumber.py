# Python3 program to count
# number of ways to group digits
# of a number such that sum of
# digits in every subgroup
# is less than or equal to its immediate
# right subgroup.

# Function to find the subgroups
def countGroups(position, previous_sum,
			length, num):

	# Terminating Condition
	if(position == length):
		return 1

	res = 0
	# sum of digits
	sum = 0

	# Traverse all digits from
	# current position to rest
	# of the length of string
	for i in range(position, length):

		sum = sum + int(num[i])
		# If forward_sum is greater
		# than the previous sum,
		# then call the method again
		if (sum >= previous_sum):
			# Note : We pass current
			# sum as previous sum
			res = res + countGroups(i + 1, sum, length, num)

	# Total number of subgroups
	# till the current position
	return res

# Driver Code
if __name__=='__main__':
	num = "1119"
	len = len(num)
	print(countGroups(0, 0, len, num))

# This code is contributed by
# Sanjit_Prasad
