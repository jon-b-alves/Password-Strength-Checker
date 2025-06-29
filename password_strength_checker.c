#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a single password to check it's strength\n");
        return 0;
    }

    if (argc > 2) {
        printf("Provided too many arguments, please enter a single password\n");
        return 0;
    }

    else {
        char *password = argv[1];
        int points = 0;

        points += check_length(password);
        points += check_digits(password);
        points += check_symbols(password);
        points += check_upper_lower(password);

        switch (points) {

            case 0:
            printf("Extremely Weak\n");
            return 0;

            case 1:
            printf("Very Weak\n");
            return 0;

            case 2:
            printf("Weak\n");
            return 0;

            case 3:
            printf("Moderate\n");
            return 0;

            case 4:
            printf("Strong\n");
            return 0;

            case 5:
            printf("Very Strong\n");
            return 0;

            case 6:
            printf("Excellent\n");
            return 0;

            case 7:
            printf("Maximum\n");
            return 0;
        }
        return 0;
    }
}
