#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - performs simple operations
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, 98 on wrong number of arguments,
 * 99 on invalid operator, 100 on division/modulo by 0
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;
    int (*op_func)(int, int);

    if (argc != 4)
    {
        _putchar("Error
");
        return (98);
    }
num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    op_func = get_op_func(argv[2]);

    if (op_func == NULL)
    {
        _putchar("Error
");
        return (99);
    }

    if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
    {
        _putchar("Error
");
        return (100);
    }

    result = op_func(num1, num2);
    _putchar(result);

    return (0);
}
