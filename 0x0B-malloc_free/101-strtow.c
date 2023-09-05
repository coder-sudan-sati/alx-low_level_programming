#include "main.h"
#include <stdlib.h>
#include <string.h>

char **strtow(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }
    
    int i, j, k, len = strlen(str), word_count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != ' ' && (i == 0 || str[i-1] == ' ')) {
            word_count++;
        }
    }
    
    char **words = (char **)malloc((word_count+1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }
    
    int word_len;
    for (i = 0, j = 0; i < word_count; i++) {
        while (str[j] == ' ') {
            j++;
        }
        word_len = 0;
        k = j;
        while (str[k] != ' ' && k < len) {
            word_len++;
            k++;
        }
        words[i] = (char *)malloc((word_len+1) * sizeof(char));
        if (words[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }
        strncpy(words[i], &str[j], word_len);
        words[i][word_len] = '\0';
        j = k;
    }
    words[word_count] = NULL;
    
    return words;
}
