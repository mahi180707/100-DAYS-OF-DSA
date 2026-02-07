#include <stdio.h>

int main() {
    int n, i, j;

    // Read number of elements
    scanf("%d", &n);

    int arr[n];

    // Read sorted array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: empty array
    if(n == 0) {
        return 0;
    }

    // j points to index of last unique element
    j = 0;

    for(i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for(i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
