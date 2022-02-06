#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * simplifyPath(char * path)
{
	char *simplified = malloc((strlen(path) + 1) * sizeof(char));
	int i, j = 0;
	for (i = 0; i < strlen(path); i++) {
		if (path[i] == '.' && path[i - 1] == '/') {
			int k, dot_count = 0;
			bool flag_move = false;
			for (k = i; !flag_move; k++) {
				flag_move = path[k + 1] == '/' || 
					path[k + 1] == '\0';
				dot_count++;
				if (path[k] != '.' || dot_count >= 3) {
					flag_move = false;
					break;
				}
			}
			if (flag_move) {
				if (dot_count == 1) {
					i++;
					continue;
				} else {
					k = j - 2;
					if (k < 0) {
						i += 2;
						continue;
					}
					while (simplified[k] != '/')
						k--;
					j = k + 1;
					i += 2;
					continue;
				}
			}
		}
		if (path[i] == '/' && simplified[j - 1] == '/')
			continue;
		simplified[j++] = path[i];
	}
	for (i = j - 1; i > 0; i--) {
		if (simplified[i] == '/')
			j--;
		else break;
	}
	simplified[j] = '\0';
	return simplified;
}

int main()
{
	printf("%s\n", simplifyPath("/home/"));
	printf("%s\n", simplifyPath("//..//"));
	printf("%s\n", simplifyPath("/../"));
	printf("%s\n", simplifyPath("/home//foo/"));
	printf("%s\n", simplifyPath("/home/../foo/"));
	printf("%s\n", simplifyPath("/home/./foo/"));
	printf("%s\n", simplifyPath("/home/.bruh/foo/"));
	printf("%s\n", simplifyPath("/home/..bruh/foo/"));
	printf("%s\n", simplifyPath("/home/...bruh/foo/"));
	printf("%s\n", simplifyPath("/home/.../foo/"));
	printf("%s\n", simplifyPath("/home/.bruh../foo/"));
	printf("%s\n", simplifyPath("/a/./b/../../c/"));
	printf("%s\n", simplifyPath("/a/../../b/../c//.//"));
	printf("%s\n", simplifyPath("/home"));
	printf("%s\n", simplifyPath("/a//b////c/d//././/.."));
}
