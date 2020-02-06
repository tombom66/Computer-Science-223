#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#define MAX_TAB_INTERVAL 80

void entab(FILE* fin, FILE* fout, int tab_interval){
  int counter = 1, c;
  while((c =fgetc(fin)!=EOF&&c==''){++counter}
  int ntabs = counter / tab_interval;
  int nspaces = counter % tab_interval;
  while(ntabs-- >0){
    fputc('\t',fout);
    }
    while(nspaces-->0){
      fputc(' ',fout);
    }
    fputc(c,fout);
}
int main(int argc, const char * argv[]){
  FILE *fin,*fout;
  int tab_interval = argc == 4? atoi(argv[3]):TAB_INTERVAL;
  if(tab_interval>80){
    fprintf(stderr, "tab_interval must be <= 80 characters \n");
    exit(2);
  }
  if(open_io_files(argc, argv, &fin, &fout,3,4,"Usage:./entab inputfile outputfile tab_interval(optional)\n")){
    exit(1);
  }
  int c;
  while((c=fgetc(fin))!=EOF){
    if(c!= ' '){
      fputc(c,fout);
      }
      else{
        entab(fin, fout,tab_interval);
      }
  }
  close_io_files(2,fin,fout);
  return 0;
}
