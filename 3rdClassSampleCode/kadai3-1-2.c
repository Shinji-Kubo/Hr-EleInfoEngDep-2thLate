#include<stdio.h>

void numCombination(int arr[], int data[], int start, int end, int index, int r);
void opeCombination(int arr[], int data[], int start, int end, int index, int r);

main(void) {
	int i, j;
	int cnt = 0;

	int numArr[30];
	int numLen = 6;
	int numData[numLen];
	int numN = sizeof(numArr) / sizeof(numArr[0]);
	int opeArr[16];
	int opeLen = 4;
	int opeData[opeLen];
	int opeN = sizeof(opeArr) / sizeof(opeArr[0]);

	for (i=0; i<10; i++) {
		for (j=0; j<3; j++) {
			numArr[cnt] = i + 1;
			cnt++;
		}
	}

	cnt = 0;

	for (i=11; i<15; i++) {
		for (j=0; j<4; j++) {
			opeArr[cnt] = i;
			cnt++;
		}
	}

	numCombination(numArr, numData, 0, numN-1, 0, numLen);
}

void numCombination(int arr[], int data[], int start, int end, int index, int r) {
	int i, j;
	int cnt = 0;

	int opeArr[16];
	int opeLen = 4;
	int opeData[opeLen];
	int opeN = sizeof(opeArr) / sizeof(opeArr[0]);

	if (index == r) {
		for (i=0; i<r; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		for (i=11; i<15; i++) {
			for (j=0; j<4; j++) {
				opeArr[cnt] = i;
				cnt++;
			}
		}
		opeCombination(opeArr, opeData, 0, opeN-1, 0, opeLen);
		return;
	}

	for (i=start; i<=end && end-i+1 >= r-index; i++) {
		data[index] = arr[i];
		numCombination(arr, data, i+1, end, index+1, r);
	}
}

void opeCombination(int arr[], int data[], int start, int end, int index, int r) {
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
		opeCombination(arr, data, i+1, end, index+1, r);
	}
}
