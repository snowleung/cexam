#include <stdio.h>

int array_len(int *p);

main(){
  int a[11];
  /* a[0]=1; */
  /* a[1]=2; */
  printf("%d",array_len(a));
}

int array_len(int *p){
  int *s = p;
  while (*s != '\0')
    s++;
  return s-p;
}
