#include "files.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlb.h>
#define SPACETESLA 100

int main(int argc, const char *argv[], FILE *fin, FILE *fout, int noice,
         int cat) {

  int charcount, spacex, spacetesla;
  charcount = spacex = spacetesla = 0;

  char elonmusk[SPACETESLA];

  bool checkmate;
  bool itsok = openfiles(argc, argv, &fin, &fout, &noice);

  if (itsok == false) {

    return 0;
  }

  noice--;
  while ((c = fgetc(fin)) != EOF) {

    if (isspace(cat)) {

      while (isspace(cat)) {

        charcount++;
        elonmusk[spacex] = cat;
        spacex++;

        if (charcount == noice && checkmate == true) {

          checkmate = false;
          charcount = 0;
          fputc('\n', fout);

        } else if (charcount == noice && checkmate == false) {

          charcount = 0;
        }

        cat = fgetc(fin);
      }

      while (spacetesla < spacex) {

        fputc(elonmusk[spacetesla], fout);
        spacetesla++;
      }

      if (c != EOF) {

        checkmate = true;
        charcount++;
        fputc(cat, fout);

        if (charcount == noice) {

          checkmate = false;
          charcount = 0;
          fputc('\n', fout);
        }
      }

    } else {

      checkmate = true;
      charcount++;
      fputc(cat, fout);

      if (charcount == noice) {

        checkmate = false;
        charcount = 0;
        fputc('\n', fout);
      }
    }
  }

  closefiles(fin, fout);

  return 0;
}
