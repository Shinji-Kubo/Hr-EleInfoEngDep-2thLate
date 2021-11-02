#include<stdio.h>

void combinationUtil(int arr[], int data[], int start, int end, int index, int r);
void printCombination(int arr[], int n, int r);

main(void) {
	int i, j;
	int cnt = 0;

	int arr[30];
	int r = 6;
	int n = sizeof(arr) / sizeof(arr[0]);

	for (i=0; i<10; i++) {
		for (j=0; j<3; j++) {
			arr[cnt] = i + 1;
			cnt++;
		}
	}

	printCombination(arr, n, r);

	return 0;
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r) {
	int i;

	if (index == r) {
		for (i=0; i<r; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return;
	}

	for (i=start; i<=end && end-i+1 >= r-index; i++) {
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1, r);
	}

}

void printCombination(int arr[], int n, int r) {
	int data[r];

	combinationUtil(arr, data, 0, n-1, 0, r);
}
