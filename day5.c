#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];
    int i = 0, j = 0, k = 0;

    // Input size of first log
    scanf("%d", &p);

    // Input first sorted array
    for(i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input size of second log
    scanf("%d", &q);

    // Input second sorted array
    for(i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;   // pointer for first array
    j = 0;   // pointer for second array

    // Merge both arrays
    while(i < p && j < q) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of first array
    while(i < p) {
        c[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of second array
    while(j < q) {
        c[k] = b[j];
        j++;
        k++;
    }

    // Print merged array
    for(i = 0; i < p + q; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
