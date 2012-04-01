#include <stdio.h>
#define MAXLINE 5


int _getline(char x[],int lim);


main(){
  int line;
  char m[MAXLINE];
  
  if((line=_getline(m,MAXLINE))>0) 
    printf("%s",m);
  else
    printf("bad!");
  return 0;
}

int _getline(char s[],int lim){
  int c,i=0;
  while(lim-->0 && (c=getchar())!=EOF && c!='\n'){
    s[i++] = c;
  }
  s[i]='\0';
  return i;
}
