#include "main.h"

/**
 * print_square - prints a square of size size
 * @size: size of the square
 *
 * Return: void
 */


void print_triangle(int size)
{
	int i, j,k;
        k = size;
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size); j++)
		{ 
                   if(j<k-1){
                      _putchar(' ');     
                   }
                   else
                      {
        	        _putchar('#');
                      }
		}
		_putchar('\n');
	}
		k--;

}
