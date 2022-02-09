#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int divide(int dividend, int divisor)
{	
	if (dividend == INT_MIN && divisor == -1)
		return INT_MAX;
	if (divisor == -1)
		return -1 * dividend;
	if (divisor == 1)
		return dividend;
	int quotient = 0, divisor_cp = divisor, neg = 1, res, dividend_cp;
	if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
		neg = -1;
	if (dividend < 0 && divisor_cp > 0)
		divisor_cp = -1 * divisor_cp;
	else if (dividend > 0 && divisor_cp < 0) {
		if (divisor_cp == INT_MIN)
			divisor_cp = INT_MAX;
		else divisor_cp = -1 * divisor_cp;
	}
	dividend_cp = (dividend == INT_MIN) ? INT_MAX : abs(dividend);
	if (abs(divisor_cp) > dividend_cp)
		return 0;
	res = divisor_cp;
	do {
		quotient++;
		int i = abs(divisor_cp);
		while (i--) {
			res = (res < 0) ? res - 1 : res + 1;
			if (res == INT_MIN || res == INT_MAX) {
				if (i == 0)
					return neg * (quotient + 1);
				else return neg * quotient;
			}
		}
	} while (abs(res) <= dividend_cp);
	return neg * quotient;
}

int main()
{
	printf("10/3 = %d\n", divide(10, 3));
	printf("16/4 = %d\n", divide(16, 4));
	printf("21/5 = %d\n", divide(21, 5));
	printf("21/7 = %d\n", divide(21, 7));
	printf("21/-7 = %d\n", divide(21, -7));
	printf("7/-3 = %d\n", divide(7, -3));
	printf("3/7 = %d\n", divide(3, 7));
	printf("INT_MIN/-1 = %d\n", divide(INT_MIN, -1));
	printf("INT_MAX/-1 = %d\n", divide(INT_MAX, -1));
	printf("INT_MIN/1 = %d\n", divide(INT_MIN, 1));
	printf("INT_MAX/1 = %d\n", divide(INT_MAX, 1));
	printf("INT_MAX/2 = %d\n", divide(INT_MAX, 2));
	printf("INT_MIN/2 = %d\n", divide(INT_MIN, 2));
	printf("INT_MAX/-2 = %d\n", divide(INT_MAX, -2));
	printf("INT_MIN/-2 = %d\n", divide(INT_MIN, -2));
	return 0;
}
