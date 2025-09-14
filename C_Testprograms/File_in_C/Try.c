#include <stdio.h>

void to_uppercase(char *str) {
    int i = 0;
    while (str[i] != '\0') {  // Loop until end of string
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a'-'A');  // Convert to uppercase
        }
        i++;
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read input string
    
    to_uppercase(str);
    
    printf("Uppercase string: %s", str);
    
    return 0;
}
