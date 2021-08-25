/*
 * name = input()
 * dob = input()
 * sex = input()
 * 
 * id = name[0]
 * dob = dob.split(':')
 * id += dob[0]
 * 
 * if (sex == 'Male'):
 *     id += dob[1]
 * else:
 *     id += str(5+int(dob[1][0]))+dob[1][1]
 * 
 * print(id)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name[30], dob[11], gender[7], res[6];
	scanf("%s\n%s\n%s", name, dob, gender);
	if (!strcmp(gender, "Male"))
		sprintf(res, "%c%c%c%c%c", name[0], dob[0], dob[1], dob[3], 
				dob[4]);
	else
		sprintf(res, "%c%c%c%c%c", name[0], dob[0], dob[1], dob[3] + 5,
				dob[4]);
	printf("%s\n", res);
}
