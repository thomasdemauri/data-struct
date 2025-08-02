#include <stdio.h>

#define N 10

int linear_search(int v[], int key, int index)
{
    if (v[index] < 0) return -1;

    if (v[index] == key) return index;

    return linear_search(v, key, index-1);
}

int main()
{
    int v[N] = {1, 2, 3, 4, 5, 6, 7, 89, 94, 120};
    int key = 94;
    int res;


    res = linear_search(v, key, N-1);

    printf("%d\n", res);
}
