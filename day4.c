#include <stdio.h>

int main() {
    int n, i;
    int a[100];
    int left, right, temp;

    // Input size
    scanf("%d", &n);

    // Input elements
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Two pointers
    left = 0;
    right = n - 1;

    // Reverse using swapping
    while(left < right) {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        left++;
        right--;
    }

    // Print reversed array
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
