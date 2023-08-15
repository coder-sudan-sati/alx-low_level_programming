#include <stdio.h>

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
