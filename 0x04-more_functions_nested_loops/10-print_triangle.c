#include "main.h"

/**
 * print_square - prints a square of size size
 * @size: size of the square
 *
 * Return: void
 */


void print_square(int size)
{
	int i, j,k;
  
	if (size <= 0)
		_putchar('\n');
   k = size;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size); j++)
		{ 
      if(j<k){
        _putchar('.');     
      }
      else
      {
        	_putchar('#');
      }
		k++
		}
		_putchar('\n');
	}

}
