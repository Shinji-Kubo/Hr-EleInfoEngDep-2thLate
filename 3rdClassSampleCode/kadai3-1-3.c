#include<stdio.h>

int temp[6];
int num = 0;

void combinationNum(int arr[], int data[], int start, int end, int index, int r);

main(void) {
    int i, j;
    int cnt = 0;

    int arr[30];
    int r = 5;
    int data[r];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (i=0; i<10; i++) {
        for (j=0; j<3; j++) {
            arr[cnt] = i + 1;
            cnt++;
        }
    }

    combinationNum(arr, data, 0, n-1, 0, r);

    printf("num : %d\n", num);

    return 0;
}

void combinationNum(int arr[], int data[], int start, int end, int index, int r) {
    int i;
    int judge = 1;

    if (index == r) {
        for (i=0; i<r; i++) {
            if (data[i] != temp[i]) {
                judge = 0;
                break;
            }
        }
        if (judge == 0) {
            for (i=0; i<r; i++) {
                temp[i] = data[i];
            }
            num++;
        }
        return;
    }

    for (i=start; i<=end && end-i+1 >= r-index; i++) {
        data[index] = arr[i];
        combinationNum(arr, data, i+1, end, index+1, r);
    }
}