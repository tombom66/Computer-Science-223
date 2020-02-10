#ifndef files_h
#define files_h

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

bool open_io_files(int argc, const char *argv[], FILE **fin, FILE **fout,
                   int min_expected_argc, int max_expected_argc,
                   const char *usage, int *d);
if (argc != 3 && argc != 4) {

  fprintf(stderr, "Usage: program.exe inputFile outputFile n");
  return false;
}

errno_t errIn = fopen_s(fin, argv[1], "r");
errno_t errOut = fopen_s(fout, argv[2], "w");

if (argc == 4) {

  *d = atoi(argv[3]);

} else {

  *d = 8;
}
return true;
}

void closefiles(FILE *fin, FILE *fout);
{
  fclose(fin);
  fclose(fout);
}
#endif /* files_h */
