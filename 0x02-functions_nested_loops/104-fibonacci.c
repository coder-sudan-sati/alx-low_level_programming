#include <stdio.h>
/**
  * main - Prints the sum of Even Fibonacci numbers
  * less than 4000000.
  *
  * Return: Nothing!
  */
int main()
{
    int a = 1, b = 2, c, count = 2;
    printf("%d, %d, ", a, b);
    while (count < 98)
    {
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;
        count++;
    }
    printf("\n");
    return 0;
}
