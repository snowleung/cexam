#include <stdio.h>
#define MAXLINE 100

main(){
  char *p1,*p2;
  char a[MAXLINE];

  a[0]='a';
  a[1]='b';
  a[2]='\0';
  
  p1 = a;

  /* b[0]='a'; */
  /* b[1]='b'; */
  /* b[2]='\0'; */
  
  printf("%p\n",--p1);
  printf("%p",a);
  printf("%d",p1<a);
  return 0;
  /* while(*p1!='\0') */
  /*   p1++; */
  
  /* while(p1-->a) */
  /*   printf("%c",*p1); */
  /* return 0; */
}
