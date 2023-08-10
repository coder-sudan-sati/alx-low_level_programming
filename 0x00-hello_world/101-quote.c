#include <stdio.h>
#include <unistd.h>

int main(void) {
  char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
  write(2, message, 50);
  return 1;
}
