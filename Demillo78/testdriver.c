#include "find.c"
#include "stdio.h"

int len(int *A){
  return sizeof(A)/sizeof(int);
}

void print_array(int* A){
  printf("A = ");
  for(int i = 1; i < len(A); i++)
    printf("%d ", A[i]);
}


int oracle(int* A, int F){
  /* first element is a dummy variable. */
  print_array(A);
  printf("\nA[%d] = %d\n", F, A[F]);

  for(int i = 1; i < F; i ++){
    printf("%d,", A[i]);
    if(A[i] > A[F])
      return 0;
  }
  
  for(int i = F + 1; i < len(A) ; i ++){
    printf("%d,", A[i]);
    if(A[i] < A[F])
      return 0;
  }
  return 1;
  

}
 
  

int tc1(){
  int A[10] = {1, -19, 34, 0, -4, 22, 12, 222, -57, 17};
  int F = 5;
  find(A, F, 9);
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}

int tc2(){
  int A[4] = {1, 7, 9, 7};
  int F = 3;
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}

int tc3(){
  int A[5] = {1, 2, 3, 1, 10};
  int F = 3;
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}

int tc4(){
  int A[5] = {1, -5, -5, -5, -5};
  int F = 1;
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}

int tc5(){
  int A[5] = {1, 1, 3, 2, 0};
  int F = 3;
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}

int tc6(){
  int A[5] = {1, 0, 2, 3, 1};
  int F = 3;
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}


int tc7(){
  int A[10] = {1, 0};
  int F = 1;
  printf("\n%d", oracle(A, F));
  return oracle(A, F);
}


int  main(){
  /* int a[4] = {1,2,3,-1}; */
  /* find(a, 3, 2); */
  /* for(int i; i < sizeof(a)/sizeof(int); i ++){ */
  /*   printf("%d ", a[i]); */
  /* } */
  /* printf("\n%d", oracle(a, 2)); */
  tc1();
  
  int (*funcptr[7]) ()= {tc1, tc2, tc3, tc4, tc5, tc6, tc7};
  for(int i = 0; i < 7; i ++)
    (funcptr[i])();
  /* funcptr = &tc1; */
  /* tc1(); */
  /* tc2(); */
  /* tc3(); */
  /* tc4(); */
  /* tc5(); */
  /* tc6(); */
  /* tc7(); */
}
