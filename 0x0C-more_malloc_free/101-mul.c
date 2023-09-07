#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int multiply(char *num1, char *num2);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                printf("Error\n");
                return 98;
            }
        }
    }
    int result = multiply(argv[1], argv[2]);
    printf("%d\n", result);
    return 0;
}

int multiply(char *num1, char *num2) {
    int len1 = 0, len2 = 0;
    while (num1[len1] != '\0') {
        len1++;
    }
    while (num2[len2] != '\0') {
        len2++;
    }
    int *result = calloc(len1 + len2, sizeof(int));
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            result[i + j + 1] += digit1 * digit2;
        }
    }
    int carry = 0;
    for (int i = len1 + len2 - 1; i >= 0; i--) {
        int temp = (result[i] + carry) % 10;
        carry = (result[i] + carry) / 10;
        result[i] = temp;
    }
    int final_result = 0;
    for (int i = 0; i < len1 + len2; i++) {
        final_result = final_result * 10 + result[i];
    }
    free(result);
    return final_result;
}
