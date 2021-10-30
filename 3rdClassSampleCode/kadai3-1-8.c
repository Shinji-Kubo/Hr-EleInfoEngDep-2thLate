#include<stdio.h>

int permutation(int *arr, int len);

main(void) {
    int i, j, k = 0;
    int len = 6;
    int arr[30];
    int temp[6];
    int judge = 1; // 0->false 1->true

    for (i=0; i<10; i++) {
        for (j=0; j<3; j++) {
            arr[k] = i + 1;
            k++;
        }
    }

    do {
        for (i=0; i<6; i++) {
            if (arr[i] != temp[i]) {
                judge = 0;
                break;
            } 
        }
        if (judge == 0) {
            for (i=0; i<6; i++) {
                temp[i] = arr[i];
                printf("%d ", arr[i]);
            }
            judge = 1;
            printf("\n");
        }
    } while (permutation(arr, len));

    return 0;
}

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