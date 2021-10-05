#include<stdio.h>
#define N 100

main(void) {
	int i;
	int num;
	int factor[N];
	int cnt = 0;

	printf("数値を入力してください : ");
	scanf("%d", &num);

	for (i=2; i<=num; i++) {
		while (num % i == 0) {
			factor[cnt] = i;
			cnt++;
			num /= i;		
		}
	}

	for (i=0; i<cnt; i++) {
		printf("%d ", factor[i]);
	}

	printf("\n");

	return 0;
}
