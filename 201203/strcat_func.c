#include <stdio.h>
#define MAXLINE 100
int strcat(char *s,char *t);

main(){

  char a[MAXLINE],b[MAXLINE];
  b[0]='a';
  b[1]='b';
  b[2]='\0';
  char c;
  char *p=&a[0];
  
  while((c = getchar())!='\n'){
    *p=c;
    p++;
    //MAXLINE Ignore
  }
  *p='\0';
  
  if(strcat(a,b)){
    printf("%s\n",b);
  }
  else
    printf("%s","error\0");
  return 0;
  
}


int strcat(char *s,char *t){
  char *tmp = t;
  int i=0;
  while(*tmp++!='\0')
    i++;
  while(*s!='\0'){
    t[i] = *s++;
    i++;
  }
  t[i]='\0';
  return 1;
}
