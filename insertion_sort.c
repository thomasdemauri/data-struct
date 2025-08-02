#include <stdio.h>

#define N 6

void insertion_sort(int v[])
{
    for (int j=1; j < N; j++) {
        int key = v[j];
        int i = j - 1;

        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }

        v[i + 1] = key;
    }

    return;
}

void print_array(int v[])
{
    for (int j=0; j<N; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    return;
}

int main()
{
    int v[N] = {5, 3, 83, 32, 13, 1};

    printf("Initial array: ");
    print_array(v);

    insertion_sort(v);

    printf("Sorted array: ");
    print_array(v);

}