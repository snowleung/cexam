#include <stdio.h>
#define MAXLINE 5

int ggetline(char line[] , int maxline);
void ccopy(char to[] , char from[]);

main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  
  max = 0;
  while ((len = ggetline(line,MAXLINE))>1)
    {
      if (len > max)
	{
	  max = len;
	  ccopy(longest,line);
	}
    }
  if (max > 0)
    printf("%s",longest);
  return 0;
}


int ggetline(char s[],int lim)
{
  int c,i;
  for (i=0;(i<lim-1)  &&(c=getchar())!='\n'  ;++i)
      s[i] = c;
      if (c == '\n'){
	s[i] = c;
	++i;
      }
      s[i] = '\0';
      return i;

}

void ccopy(char to[] ,char from[]){
  int i ;
  i = 0;
  while((to[i] = from[i])!='\0') ++i;
}
