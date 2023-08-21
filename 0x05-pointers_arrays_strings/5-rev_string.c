#include "main.h"
#include "string.h"

/**
  * rev_string - Reverses a string
  * @s: The string to be modified
  *
  * Return: void
  */
void rev_string(char *s)
{
	strrev(*s);
	_putchar(s);
}
