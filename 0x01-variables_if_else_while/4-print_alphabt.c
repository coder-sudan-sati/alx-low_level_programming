#include <stdio.h>

/**                                                                                                                                                                                        
 * main - Prints the alphabet in lowercase.                                                                                                                                                
 *                                                                                                                                                                                         
 * Return: Always 0.                                                                                                                                                                       
 */
int main(void)
{
        char letter;

 a: for (letter = 'a'; letter <= 'z'; letter++)
	  {
	    if (letter == "e" || letter == "q")
	      {
		goto a;
	      }
                putchar(letter);

	/* for (letter = "A" ;letter <= "Z"; letter*/

        return (0);
}
