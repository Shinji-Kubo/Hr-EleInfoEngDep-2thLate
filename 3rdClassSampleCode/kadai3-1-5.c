#include<stdio.h>

int permutation(int *arr, int len) {
    int left = len - 2;
    while (left >= 0 && arr[left] >= arr[left+1]) {
        left--;
    }
    if (left < 0) {
        return 0;
    }

    int right = len - 1;
    while (arr[left] >= arr[right]) {
        right--;
    }
    
    int t = arr[left];
    arr[left] = arr[right];
    arr[right] = t;

    left++;
    right = len - 1;
    while (left < right) {
        t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;
        left++;
        right--;
    }
    return 1;
}

main(void) {
    int i;
    int len = 5;
    int arr[] = {1, 1, 1, 2, 2};

    do {
        for (i=0; i<len; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
    } while (permutation(arr, len));
}