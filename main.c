/* Vertical Histogram of words in a Sentence */

#include <stdio.h>
#define MAXWL 20 /* Maximum length of a word */
#define MAXNO 25 /* Maximum No of words in a sentence */
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
          newcork - 1; /* -1 for excluding the space in the word length */
      ++newwork;
      newcork = 0; /* resetting the word-length for the next word */
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
