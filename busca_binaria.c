#include <stdio.h>

#define N 12 // Tamanho do vetor

int main()
{
    int steps = 1; // Apenas para ajudar na explicação do exercício


    int v[N] = {2, 5, 7, 9, 23, 32, 34, 39, 42, 48, 52, 65};
    int k = 7;

    int left = 0, right = N, mid;

    while (left < right) {

        mid = left + (right - left) / 2;

        printf("\nstep %d\n", steps);
        printf("while (%d < %d)\n", left, right);
        printf("mid = (%d + %d) / 2 | mid equals %d\n", left, right, mid);

        printf("v[mid] == k ? %d == %d\n", v[mid], k);

        if (v[mid] == k) {
            printf("\n\nnumber %d found at %d index\n", v[mid], mid);
            break;
        }

        printf("checks if k [%d] is greater than v[mid] %d \n", k, v[mid]);
        if (k > v[mid]) {
            left = mid + 1;
            printf("yes, now left is equal to mid + 1 (%d + 1), left => %d\n", mid, left); 
        } else {
            right = mid;
            printf("nope, right is equal to mid, right => %d\n", right);
        }

        steps++;
   }

    printf("\ntotal steps = %d\n", steps);

}
