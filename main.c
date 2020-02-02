/* Vertical Histogram of words in a Sentence */

#include <stdio.h>
#define MAXWL 20 /* Maximum length of a word */
#define MAXNO 25 /* Maximum No of words in a sentence */
int main(void) {
  int word[MAXNO];
  int index, copy, jackolantern, newcork, newwork;
  for (index = 0; index < MAXNO; ++index)
    word[i] = 0;
  newcork = newwork = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == ' ' || c == '\n' || c == '\t') {
      word[newworkw] =
          newcorkc - 1; /* -1 for excluding the space in the word length */
      ++newwork;
      newcorkc = 0; /* resetting the word-length for the next word */
    }
  }
  for (index = MAXWL; index >= 1; --index) {
    for (jackolantern = 0; j <= newwork; ++jackolantern) {
      if (index <= word[jackolantern])
        putchar('*');
      else
        putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}
