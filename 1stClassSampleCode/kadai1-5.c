#include<stdio.h>
#include<math.h>

main(void) {
	int mer, i;
	int n = 1;
	int flag = 0; // true -> 1 false -> 0

	while (1) {
		mer = pow(2, n) - 1;

		for (i=2; i<mer; i++){
				if (mer % i == 0) {
					flag = 1;
					break;
				}
		}

		if (mer == 1 || n == 1) {
			flag = 1;
		}

		if (flag == 0) {
			for (i=2; i<n; i++) {
				if (n % i == 0) {
					flag = 1;
					break;
				}
			}
		}

		if (flag == 0) {
			printf("Value of N -> %d\n", n);
			printf("Mersenne -> %d\n", mer);
		}

		flag = 0;

		n++;

		if (n > 30) {
			break;
		}
	}

	return 0;
}
