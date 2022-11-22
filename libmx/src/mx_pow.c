double mx_pow(double n, unsigned int pow) {
	if (pow == 0) {
		return 1;
	}

	return n * mx_pow(n, pow - 1);
}


// #include <stdio.h>
// int main(void) {
// 	printf("%f\n", mx_pow(0, 1));
// 	return 0;
// }






