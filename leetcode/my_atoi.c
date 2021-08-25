/*
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit 
 * 			signed integer (similar to C/C++'s atoi function).
 * The algorithm for myAtoi(string s) is as follows:
 * Read in and ignore any leading whitespace
 * Check if the next character (if not already at the end of the string) is '-' 
 * 			or '+'. Read this character in if it is either. This 
 * 			determines if the final result is negative or positive 
 * 			respectively. Assume the result is positive if neither 
 * 			is present.
 * Read in next the characters until the next non-digit charcter or the end of 
 * 			the input is reached. The rest of the string is ignored.
 * Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If 
 * 			no digits were read, then the integer is 0. Change the 
 * 			sign as necessary (from step 2).
 * If the integer is out of the 32-bit signed integer range [-231, 231 - 1], 
 * 			then clamp the integer so that it remains in the range. 
 * 			Specifically, integers less than -231 should be clamped 
 * 			to -231, and integers greater than 231 - 1 should be 
 * 			clamped to 231 - 1.
 * Return the integer as the final result.
 * Note:
 * Only the space character ' ' is considered a whitespace character.
 * Do not ignore any characters other than the leading whitespace or the rest 
 * 			of the string after the digits.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int my_atoi(char *s);
bool is_num(char x);

int main(int argc, char* argv[])
{
	char s[1000];
	scanf("%s", s);
	printf("%d\n", my_atoi(s));
	return 0;
}

int my_atoi(char *s)
{
	if (s[0] != '\t' && s[0] != ' ' && s[0] != '+' 
			&& s[0] != '-' && !is_num(s[0]))
		return 0;
	int i, res;
	long num = 0;
	bool neg = false, num_occured = false, trailing = true;
	int num_signs = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (num_signs > 1)
			return 0;
		else if ((s[i] == ' ' || s[i] == '\t') && trailing)
			continue;
		else if (s[i] == '+' && !num_occured) {
			num_signs++;
			trailing = false;
		} else if (s[i] == '-' && !num_occured) {
			neg = true;
			num_signs++;
			trailing = false;
		} else if (is_num(s[i])) {
			num *= 10;
			num += s[i] - '0';
			num_occured = true;
			if (num > INT_MAX || num < INT_MIN)
				break;
			trailing = false;
		} else break;
	}
	if (neg)
		num *= -1;
	if (num > INT_MAX)
		res = INT_MAX;
	else if (num < INT_MIN)
		res = INT_MIN;
	else
		res = (int) num;
	return res;
}

bool is_num(char x)
{
	int i;
	for (i = 0; i < 10; i++) {
		if (numbers[i] == x)
			return true;
	}
	return false;
}
