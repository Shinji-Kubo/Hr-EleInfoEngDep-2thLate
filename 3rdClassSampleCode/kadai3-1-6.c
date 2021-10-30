#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5

typedef struct {
    int num;
    char ope;
    int judge; // 0->num 1->ope
} Data;

int stack[STACKSIZE];
int top = 0;
int tmp1;
int tmp2;


void poland(Data *data);
void push(int num);
int pop();

main(void) {
    int i, j;

    int initial[] = {
                1, 1, 1,
                2, 2, 2,
                3, 3, 3,
                4, 4, 4,
                5, 5, 5,
                6, 6, 6,
                7, 7, 7,
                8, 8, 8,
                9, 9, 9,
                10, 10, 10
                };

    char ope[] = "++++";
    int nums[] = {9, 9, 10, 10, 10};
    Data data[9];

    for (i=0; i<5; i++) {
        for (j=0; j<30; j++) {
            if (nums[i] == initial[j]) {
                initial[j] = 2000000;
                break;
            }
        }
    }

    for (i=0; i<30; i++) {
        printf("%d\n", initial[i]);
    }

    // No.1
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].num = nums[3];
    data[3].judge = 0;
    data[4].num = nums[4];
    data[4].judge = 0;
    data[5].ope = ope[0];
    data[5].judge = 1;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.2
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].num = nums[3];
    data[3].judge = 0;
    data[4].ope = ope[0];
    data[4].judge = 1;
    data[5].num = nums[4];
    data[5].judge = 0;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.3
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].num = nums[3];
    data[3].judge = 0;
    data[4].ope = ope[0];
    data[4].judge = 1;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].num = nums[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.4
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].num = nums[3];
    data[3].judge = 0;
    data[4].ope = ope[0];
    data[4].judge = 1;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = nums[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.5
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].num = nums[3];
    data[4].judge = 0;
    data[5].num = nums[4];
    data[5].judge = 0;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.6
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].num = nums[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].num = nums[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.7
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].num = nums[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = nums[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.8
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = nums[3];
    data[5].judge = 0;
    data[6].num = nums[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.9
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].num = nums[2];
    data[2].judge = 0;
    data[3].ope = ope[0];
    data[3].judge = 1;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = nums[3];
    data[5].judge = 0;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = nums[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.10
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = nums[2];
    data[3].judge = 0;
    data[4].num = nums[3];
    data[4].judge = 0;
    data[5].num = nums[4];
    data[5].judge = 0;
    data[6].ope = ope[1];
    data[6].judge = 1;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.11
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = nums[2];
    data[3].judge = 0;
    data[4].num = nums[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].num = nums[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.12
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = nums[2];
    data[3].judge = 0;
    data[4].num = nums[3];
    data[4].judge = 0;
    data[5].ope = ope[1];
    data[5].judge = 1;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = nums[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.13
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = nums[2];
    data[3].judge = 0;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = nums[3];
    data[5].judge = 0;
    data[6].num = nums[4];
    data[6].judge = 0;
    data[7].ope = ope[2];
    data[7].judge = 1;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);
    // No.14
    top = 0;
    data[0].num = nums[0];
    data[0].judge = 0;
    data[1].num = nums[1];
    data[1].judge = 0;
    data[2].ope = ope[0];
    data[2].judge = 1;
    data[3].num = nums[2];
    data[3].judge = 0;
    data[4].ope = ope[1];
    data[4].judge = 1;
    data[5].num = nums[3];
    data[5].judge = 0;
    data[6].ope = ope[2];
    data[6].judge = 1;
    data[7].num = nums[4];
    data[7].judge = 0;
    data[8].ope = ope[3];
    data[8].judge = 1;
    poland(data);
    printf("%d\n", stack[0]);

    return 0;
}

void poland(Data *data) {
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
                push(tmp2/tmp1);
            }
        }
        data++;
    }
}
    

void push(int num) {
    if (top > STACKSIZE - 1) {
        exit(1);
    }

    stack[top] = num;
    top++;
}

int pop() {
    if (top == 0) {
        exit(1);
    }
    top--;
    return stack[top];
}