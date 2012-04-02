#include <stdio.h>
#include <time.h>

#define MAXLINE 5

int binsearch(int x,int a[],int lenth);

main(){
  clock_t start_time = clock();
  
  int a[MAXLINE]={1,2,3,4,5};
  
  printf("%d",binsearch(2,a,MAXLINE));
  
  clock_t end_time = clock();
  printf("\n%f",(double)(end_time-start_time)/CLOCKS_PER_SEC*1000);


}

int binsearch(int x,int a[],int length){
  int low,high,mid;
  low = 0;
  high = length-1;
  while (low <=high){
    mid = (low+high)/2;
    if(x<=a[mid])
      high=mid-1;
    else
      low = mid+1;
  }
  if(x == a[mid]) return mid;  
  return -1;
}
