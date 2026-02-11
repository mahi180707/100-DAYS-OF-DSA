#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right, isPalindrome = 1;

    // Read input string
    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
