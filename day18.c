#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    int temp[n];

    // Copy last k elements to beginning
    for(i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
