#include <stdio.h>
#define MAX 1000
int readtext(char[],int);
void reverse (char[]);
int main(void){
char text[MAX] //ctrl z exit thing 
printf("enter some text(control z to exit the program)\n\n");
while((readtext(text, sizeof text)>0)){
reverse(text);
printf("%s\n\n",text);
}
return 0;
}

int readtext(char a[], int len)//used to return the size of the function
{
int letchar;
for(int i = 0;i<len-1 && (letchar = getchar())!=EOF && letchar != '\n';i++)
a[i] = letchar;
if(letchar=='\n')
a[i++]=letchar;
a[i]='\0'
return i;

}
void reverse(char a[])
{
char t;
int x,y;
for(y=0;a[y]!='\0';y++)
--y;
for(x=0;x<y;x++){
t=a[x];
a[x]=a[y];
a[y]=t;
--y;
}
}
