#include <stdio.h>
#include <string.h>
#include <ctype.h>

//TODO:
//take input from terminal (command-line argument)

int check_length(const char *password) {
    int password_len = strlen(password);

    if (password_len == 6 || password_len == 7) {
        return 1;
    }

    if (password_len >= 8 && password_len <= 11) {
        return 2;
    }
    
    if (password_len >= 12 && password_len <= 15) {
        return 3;
    }
    
    if (password_len >= 16) {
        return 4;
    }
}

int check_digits(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_symbols(const char *password) {
    const char *symbols = "!@#$%^&*()-_=+[]{}|;:',.<>?/\\`~";
    for (int i = 0; password[i] != '\0'; i++) {
        for(int j = 0; symbols[j] != '\0'; j++) {
            if (password[i] == symbols[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int check_upper_lower(const char *password) {
    int lower = 0;
    int upper = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (lower == 1 && upper == 1) {
            return 1;
        }

        if (password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        }

        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        }
    }
    return 0;
}

int main() {
    
    char *password = "Abcdefghjkabcdefghuwerdfkjh123$";
    int points = 0;

    points += check_length(password);
    points += check_digits(password);
    points += check_symbols(password);
    points += check_upper_lower(password);

    printf("%d\n", check_length(password));
    printf("%d\n", check_digits(password));
    printf("%d\n", check_symbols(password));
    printf("%d\n", check_upper_lower(password));

    printf("%d\n", points);
    return 0;
}
