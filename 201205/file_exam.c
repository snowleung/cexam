#include <stdio.h>

main (){
  FILE *p;
  printf("%s","p");
  if ((p = fopen("/home/snow/Desktop/style.css","r"))!=NULL){
    printf("%s","p2");
    int c;
    char s[256];
    fscanf(p,"%s",s);
    fprintf(stdout,"%s\n","试试中文");
    fprintf(stdout,"%s\n",s);

    char *p = "试试中文\0";

    int i = strlen(p);
    printf("\n%s\n",p);
    printf("\n%d\n",i);
      //    putc(s,stdout);
  }
  
   
  

  return 0;
}
