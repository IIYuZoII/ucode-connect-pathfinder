#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
	int res = 0;
	int len_s1 = mx_strlen(s1);
	int len_s2 = mx_strlen(s2);
	if (len_s1 > len_s2) {
		return 1;
	}
	else if (len_s1 < len_s2) {
		return -1;
	}
	for (int i = 0; ; i++) {
		if (s1[i] == '\0' || s2[i] == '\0') break;
		if (s1[i] != s2[i]) {
			res = s1[i] - s2[i];
			break;
		} 
	}
	return res;
}







