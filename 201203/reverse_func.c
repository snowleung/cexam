#include <stdio.h>
#define MAXLINE  1000


int reverse(char *p,int len);

main(){
  int c,strlen,i;
  char line[MAXLINE];
  i = 0;
    
  while((c = getchar())!= '\n'){
    line[i] = c;
    i++;
    if (i>MAXLINE) break;
  }
  strlen = i;
  if (reverse(line,i)==0)
    for (i=0;i<strlen;i++){
      printf("%c",line[i]);
    }
  else
    printf("%s","cnt");
  return 0;
}

int reverse(char *p,int len)
{
  char *pend ;
  pend = p+len-1;  
  char swap;
  int m;
  while(1){

    swap = *p;
    *p = *pend;
    *pend = swap;
    if (p==pend||(p+1) == pend) break;
    p++;pend--;
  }
  return 0;
}
