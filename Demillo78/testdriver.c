#include "find.c"
/* #include "util.c" */
#include "stdio.h"



int oracle(int* A, int F, int N){
  /* A[0] is dummy, ignore!  */
  int i;
  for(i = 1; i < F; i ++){

    if(A[i] > A[F])
      return 0;
  }
  for(i = F + 1; i < N ; i ++){
    if(A[i] < A[F])
      return 0;
  }
  return 1;
}  


 
  

int tc1(){
  /* A[0] is dummy, ignore!  */
  int A[10] = {1, -19, 34, 0, -4, 22, 12, 222, -57, 17};
  int F = 5;
  int N = sizeof(A)/sizeof(A[0]);
  find(A, F, N);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);  
}

int tc2(){
  int A[4] = {1, 7, 9, 7};
  int F = 3;
  int N = sizeof(A)/sizeof(A[0]);
  find(A, F, N);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);
}

int tc3(){
  int A[5] = {1, 2, 3, 1, 10};
  int F = 3;
  int N = sizeof(A)/sizeof(A[0]);
  find(A, F, N);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);
}
 
int tc4(){
  int A[5] = {1, -5, -5, -5, -5};
  int F = 1;
  int N = sizeof(A)/sizeof(A[0]);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);
}

int tc5(){
  int A[5] = {1, 1, 3, 2, 0};
  int F = 3;
  int N = sizeof(A)/sizeof(A[0]);
  find(A, F, N);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);
}

int tc6(){
  int A[5] = {1, 0, 2, 3, 1};
  int F = 3;
  int N = sizeof(A)/sizeof(A[0]);
  find(A, F, N);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);
}


int tc7(){
  int A[10] = {1, 0};
  int F = 1;
  int N = sizeof(A)/sizeof(A[0]);
  find(A, F, N);
  printf("%d\n", oracle(A, F, N));
  return oracle(A, F, N);
}


int  main(){
  /* Demillo's magic test cases. */
  int (*funcptr[7]) ()= {tc1, tc2, tc3, tc4, tc5, tc6, tc7};
  int i;  
  for(i = 0; i < 7; i ++){
    printf("tc%d\n", i+1);
    (funcptr[i])();}

}
