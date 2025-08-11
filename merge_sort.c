#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000   // Change here to analyze algorithm efficiency

void print_array(int v[], int len) {
    for (int j = 0; j < len; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");
}

void merge(int v[], int aux[], int start, int mid, int end)
{
    int i = start, j = mid+1, k = start;    // i (start) j (mid) k (v)

    for (int z=start; z<=end; z++) {
        aux[z] = v[z];
    }

    while (i <= mid && j <= end) {
       if (aux[i] < aux[j]) {
        v[k++] = aux[i++]; 
       } else {
        v[k++] = aux[j++];
       }
    }

    while (i<=mid) {
        v[k++] = aux[i++];
    }

    while (j<=end) {
        v[k++] = aux[j++];
    }

    return;

}

void merge_sort(int v[], int aux[], int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(v, aux, start, mid);
        merge_sort(v, aux, mid+1, end);
        merge(v, aux, start, mid, end);
    }

    return;
}


int main() {

    int aux[N];
    int v[N];

    srand(time(NULL));
    
    printf("Loading...");
    for (int i=0; i<N;i++) {
        v[i] = rand();
    }

    printf("Sorting...");
    merge_sort(v, aux, 0, N - 1);

    print_array(v, N);
    return 0;
}