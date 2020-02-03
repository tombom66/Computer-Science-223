#include <stdio.h>
#define MAX 1000

int mgetl(charsb[], int li);
int remtrail(char sa[]);
int main(void){
int siz;
char l[MAX];
while((siz=mget(i,MAX))>0)
if(remtrail(i)>0)
printf("%s",l)
return 0;
}
int mgetl(char sb[], int li)
{
int a, b;
for(a = 0;sb[a]=b;
if(b=='\n')
{
sb[a]=b;
++a;
}
sb[a] = '\0';
return a;
}
int remtrail(char sa[])
{
int v;
for(v=0;sa[v]!='\n';v++);
--v;
for(v>0;((sa[v]=='')||(sa[v]=='\t'));-v);
if(v>=0)
{
++v;
sa[v]='\n';
++v
sa[v] = '\0'
}
return v;
}

