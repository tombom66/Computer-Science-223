#include "files.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[], FILE *fin, FILE *fout, int noice,
         int cat) {

  bool itsok = openfiles(argc, argv, &fin, &fout, &noice);

  if (itsok == false) {

    return 0;
  }
  while ((cat = fgetc(fin)) != EOF) {

    if (cat == '\"') {

      fputc(cat, fout);
      cat = fgetc(fin);

      if (cat != EOF) {
        fputc(cat, fout);
        while (cat != '\"') {
          if (cat == '\\') {

            cat = fgetc(fin);
            fputc(c, fout);
          }
          cat = fgetc(fin);
          fputc(cat, fout);
        }
      }

    } else if (cat == '\'') {

      fputc(cat, fout);
      cat = fgetc(fin);
      if (cat != EOF) {
        fputc(cat, fout);
        while (cat != '\'') {
          if (cat == '\\') {

            cat = fgetc(fin);
            fputc(cat, fout);
          }
          cat = fgetc(fin);
          fputc(cat, fout);
        }
      }

    } else if (cat == '/') {

      cat = fgetc(fin);
      if (cat != EOF && cat == '/') {

        while (cat != '\n' && cat != EOF) {
          cat = fgetc(fin);
        }

      } else if (cat != EOF && cat == '*') {

        while (cat != '/' && cat != EOF) {
          cat = fgetc(fin);
        }
      }

    } else {

      fputc(cat, fout);
    }
  }

  closefiles(fin, fout);

  return 0;
}
