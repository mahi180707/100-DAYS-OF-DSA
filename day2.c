#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Create new array with size n+1
    int new_arr[n+1];
    
    // Copy elements before insertion position
    for(int i = 0; i < pos - 1; i++) {
        new_arr[i] = arr[i];
    }
    
    // Insert the element at pos (converting 1-based to 0-based index)
    new_arr[pos - 1] = x;
    
    // Copy remaining elements and shift them right
    for(int i = pos - 1; i < n; i++) {
        new_arr[i + 1] = arr[i];
    }
    
    // Print the updated array
    for(int i = 0; i <= n; i++) {
        printf("%d", new_arr[i]);
        if(i < n) printf(" ");
    }
    printf("\n");
    
    return 0;
}
