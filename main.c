

#include <stdio.h>
#define MAXWL 20 
#define MAXNO 25 
int main(void) {
  int word[MAXNO];
  int index, copy, jackolantern, newcork, newwork;
  for (index = 0; index < MAXNO; ++index)
    word[index] = 0;
  newcork = newwork = 0;
  while ((copy = getchar()) != EOF) {
    ++newcork;
    if (copy == ' ' || copy == '\n' || copy == '\t') {
      word[newwork] =
          newcork - 1; 
      ++newwork;
      newcork = 0; /
    }
  }
  for (index = MAXWL; index >= 1; --index) {
    for (jackolantern = 0; jackolantern <= newwork; ++jackolantern) {
      if (index <= word[jackolantern])
        putchar('*');
      else
        putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}
