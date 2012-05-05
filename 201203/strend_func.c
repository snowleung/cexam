#include <stdio.h>
#define MAXLINE 100
int strend(char *s,char *t);

main(){
  char a[MAXLINE],b[MAXLINE];
  a[0]='a';
  a[1]='b';
  a[2]='\0';


  b[0]='x';
  b[1]='b';
  b[2]='\0';
  if (strend(a,b))
    printf("find it!");
  else
    printf("not found");
  return 0;
}

int strend(char *s,char *t){
  int len_s = 0,len_t=0,flag=1;
  char *tmp_s=s;
  char *tmp_t=t;


  while(*tmp_s++!='\0')
    len_s++;
  while(*tmp_t++!='\0')
    len_t++;

  tmp_s-=1;
  tmp_t-=1;
  
  /* while((tmp_t>t)&&(flag=!(*--tmp_t!=*--tmp_s))) */
  /*   printf("%c",*tmp_s); */
  /* return flag; */

  /* for(;tmp_t>t;printf("now --\n%c\n",*tmp_t),tmp_t--,tmp_s--){ */
  /*   printf("now loop\n%c\n|",*tmp_t); */
  /*   if (*tmp_t!=*tmp_s){ */
  /*     flag = 0; */
  /*     break; */
  /*   } */
  /* } */
  /* return flag; */

  /* while(!(tmp_t==t)){ */
  /*   if(*tmp_t--!=*tmp_s--){ */
  /*     flag=0; */
  /*     break; */
  /*   } */
  /* } */
  /* return flag; */
  while(!(tmp_t<t)){    
    if (*tmp_t--!=*tmp_s--){
      flag = 0;
      break;
    }
  }
  return flag;
}
