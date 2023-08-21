#include "main.h"
#include <string.h>

/**
  * rev_string - Reverses a string
  * @s: The string to be modified
  *
  * Return: void
  */
void rev_string(char *s) {
   int len = strlen(s);
   char *start = s;
   char *end = s + len - 1;
   
   while (start < end) {
      char temp = *start;
      *start = *end;
      *end = temp;
      
      start++;
      end--;
   }
   
   s[len] = '\0';
}


