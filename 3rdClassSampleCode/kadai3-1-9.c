#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACKSIZE 5

typedef struct {
    int num;
    char ope;
    int judge; // 0->num 1->ope
} Data;

int stack[STACKSIZE];
int top = 0;
int cnt = 0;
char opePmt[4][256];
int temp[5];
int initial[30];
int buf = 1;
int tmp1;
int tmp2;
int cannot = 0;

void initialize(void);
void check(int data[]);
int compare (const void * a, const void * b);
void allLexicographicRecur (char *str, char* data, int last, int index);
void allLexicographic(char *str);
void combinationNum(int arr[], int data[], int start, int end, int index, int r);
int permutation(int *arr, int len);
void calculation(char ope[], int num[], int x);
int poland(Data *data);
void push(int num);
int pop();

main(void) {

    initialize();

    // operation permutation repeatation
    int i, j;
    char ope[] = "+-*/";

    allLexicographic(ope);

    // number combination
    int k = 0;
    int arr[30];
    int r = 5;
    int data[r];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (i=0; i<10; i++) {
        for (j=0; j<3; j++) {
            arr[k] = i + 1;
            k++;
        }
    }

    combinationNum(arr, data, 0, n-1, 0, r);

    printf("%d\n", cannot);
    return 0;
}

void initialize(void) {
    int i, j, k = 0;

    for (i=0; i<10; i++) {
        for (j=0; j<3; j++) {
            initial[k] = i + 1;
            k++;
        }
    }
}

void check(int data[]) {
    int i, j;

    for (i=0; i<5; i++) {
        for (j=0; j<30; j++) {
            if (data[i] == initial[j]) {
                initial[j] = 2000000;
                break;
            }
        }
    }
}

void allLexicographicRecur (char *str, char* data, int last, int index) {
    int i, j, len = strlen(str);
 
    for ( i=0; i<len; i++ ){
        data[index] = str[i];
 
        if (index == last) {
            for (j=0; j<4; j++) {
                opePmt[j][cnt] = *(data+j);
            }
            cnt++;
        }
        else {
            allLexicographicRecur (str, data, last, index+1);
        }
    }
}

void allLexicographic(char *str) {
    int len = strlen(str);

    char *data = (char *) malloc (sizeof(char) * (len + 1)) ;
    data[len] = '\0';

    qsort(str, len, sizeof(char), compare);

    allLexicographicRecur(str, data, len-1, 0);

    free(data);
}

int compare (const void * a, const void * b) {
    return ( *(char *)a - *(char *)b );
}

void combinationNum(int arr[], int data[], int start, int end, int index, int r) {
    int i, j, k;
    int judge = 1;
    char ope[4];

    if (index == r) {
        for (i=0; i<r; i++) {
            if (data[i] != temp[i]) {
                judge = 0;
                break;
            }
        }
        if (judge == 0) {

            check(data);

            // number permutation
            for (k=0; k<30; k++) {
                if (initial[k] == 2000000) {
                    continue;
                }
                do {
                    // operation process
                    for (i=0; i<256; i++) {
                        for (j=0; j<4; j++) {
                            ope[j] = opePmt[j][i];
                        }
                        calculation(ope, data, initial[k]);
                        if (buf == 0) {
                            break;
                        }
                    }
                    if (buf == 0) {
                        break;
                    }
                } while (permutation(data, r));

                if (buf == 0) {
                    buf = 1;
                } else {
                    printf("%d\n", cannot);
                    cannot++;
                }
            }
            judge = 1;

            initialize();
        }
        return;
    }

    for (i=start; i<=end && end-i+1 >= r-index; i++) {
        data[index] = arr[i];
        combinationNum(arr, data, i+1, end, index+1, r);
    }
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

void calculation(char ope[], int num[], int x) {
int i, j, k = 0;
    Data data[9];

    // No.1
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].num = num[3];
    data[3].judge = 0;
    data[4].num = num[4];
    data[4].judge = 0;
    data[5].ope = ope[0];
    data[5].judge = 1;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.2
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].num = num[3];
    data[3].judge = 0;
    data[4].ope = ope[0];
    data[4].judge = 1;
    data[5].num = num[4];
    data[5].judge = 0;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.3
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].num = num[3];
    data[3].judge = 0;
    data[4].ope = ope[0];
    data[4].judge = 1;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].num = num[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.4
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].num = num[3];
    data[3].judge = 0;
    data[4].ope = ope[0];
    data[4].judge = 1;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = num[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.5
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].num = num[3];
    data[4].judge = 0;
    data[5].num = num[4];
    data[5].judge = 0;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.6
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].num = num[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].num = num[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.7
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].num = num[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = num[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.8
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = num[3];
    data[5].judge = 0;
    data[6].num = num[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.9
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].num = num[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = num[3];
    data[5].judge = 0;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = num[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.10
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = num[2];
    data[3].judge = 0;
    data[4].num = num[3];
    data[4].judge = 0;
    data[5].num = num[4];
    data[5].judge = 0;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.11
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = num[2];
    data[3].judge = 0;
    data[4].num = num[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].num = num[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.12
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = num[2];
    data[3].judge = 0;
    data[4].num = num[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = num[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.13
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = num[2];
    data[3].judge = 0;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = num[3];
    data[5].judge = 0;
    data[6].num = num[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
    // No.14
    top = 0;
    data[0].num = num[0];
    data[0].judge = 0;
    data[1].num = num[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = num[2];
    data[3].judge = 0;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = num[3];
    data[5].judge = 0;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = num[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    if (poland(data) != 1) {
        if (stack[0] == x) {
            buf = 0;
            return;
        }
    }
}

int poland(Data *data) {
    int i;

    for (i=0; i<9; i++) {
        if (data->judge == 0) {
            push(data->num);
        } else {
            tmp1 = pop();
            tmp2 = pop();
            if (data->ope == '+') {
                push(tmp2+tmp1);
            } else if (data->ope == '-') {
                push(tmp2-tmp1);
            } else if (data->ope == '*') {
                push(tmp2*tmp1);
            } else {
                if (tmp1 == 0) {
                    return 1;
                }
                push(tmp2/tmp1);
            }
        }
        data++;
    }

    return 0;
}

void push(int num) {
    if (top > STACKSIZE - 1) {
        printf("OVERFLOW\n");
        exit(1);
    }

    stack[top] = num;
    top++;
}

int pop() {
    if (top == 0) {
        printf("UNDERFLOW\n");
        exit(1);
    }
    top--;
    return stack[top];
}