#include <stdio.h>

#define N 10

void convert_to_binary(int decimal_number, int v[])
{
    int curr_num = decimal_number;
    int i = N-1;  // Last index

    while (curr_num > 0) {
        v[i] = curr_num % 2;
        curr_num /= 2;
        i--;
    }

    return;
}

int main()
{
    int decimal_number = 62;
    int binary_arr[N] = {0};

    convert_to_binary(decimal_number, binary_arr);

    printf("number %d in binary is => ", decimal_number);

    for (int i=0; i<N; i++) {
        printf("%d", binary_arr[i]);
    }

    printf("\n");
}
