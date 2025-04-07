#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, K[6],J[6];
  for(i=0;i<6;i++){
    scanf("%d",&K[i]);
  }
  for(i=0;i<6;i++){
    if (i % 2 != 0){
    J[i] = K[i - 1];
    }if (i % 2 ==0){
    J[i] = K[i + 1];
    }
  }
  for(i=0;i<6;i++){
    printf("\n%d",J[i]);
  }
    return(0);
}

