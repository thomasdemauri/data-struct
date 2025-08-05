#include <stdio.h>

void print_array(int v[], int len)
{
    for (int j=0; j<len; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    return;
}

void selection_sort(int v[], int len)
{
    for (int j=0; j<len-1; j++) {

        int smallest_index = j;

        for (int k=j+1; k<len; k++) {

            if (v[k] < v[smallest_index]) smallest_index = k;

        }

        int tmp = v[smallest_index];
        v[smallest_index] = v[j];
        v[j] = tmp;

    }
}

int main()
{

    int v[3] = {5, 4, 3};
    selection_sort(v, 3);
    print_array(v, 3);

    return 0;
}