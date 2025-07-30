#include <stdio.h>

#define N 6

int r_binary_search(int v[], int key, int left, int right)
{
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (v[mid] == key) return mid;

    if (v[mid] > key) {
        right = mid;
    } else {
        left = mid + 1;
    }

    return r_binary_search(v, key, left, right); 
}

int main()
{
    int v[N] = {2, 3, 5, 6, 8, 11};
    int res, key = 19;

    res = r_binary_search(v, key, 0, N-1);

    if (res == -1) {
        printf("number %d was not found in array\n", key);
    } else {
        printf("number %d found at %d index array position\n", key, res);
    }
}
