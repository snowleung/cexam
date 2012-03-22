#include <stdio.h>
#define MAXLINE  1000


int reverse(char *p,int len);

main(){
  int c,strlen,i;
  char line[MAXLINE];
  i = strlen = 0;
  
  /* while((c = getchar())!= '\n'){ */
  /*   line[i++] = c; */

  /* } */
  /* printf("%s ",line); */
  /* return 0; */
  
  while((c = getchar())!= '\n'){
    line[i] = c;
    i++;
    /* if (i>MAXLINE) break;     */
  }
  if (reverse(line,i)==0)
    printf("%s",line);
  else
    printf("%s","cnt");
  return 0;
}

int reverse(char *p,int len)
{
  char *pend ;
  pend = p+len-1;  
  char swap;
  for (;p!=pend&&(p+1)!=pend;p++,pend--){
    swap = *p;
    *p = *pend;
    *pend = swap;
  }
  return 0;
}
