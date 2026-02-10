#include <stdio.h>

// Recursive function to calculate power
int power(int a, int b) {
    if (b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Input two integers
    scanf("%d %d", &a, &b);

    // Output result
    printf("%d", power(a, b));

    return 0;
}
