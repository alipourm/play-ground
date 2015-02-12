/*This program is C translation of Find algorithm in Demillo's 78 paper. The title of paper is:
R. A. DeMillo, R. J. Lipton, and F. G. Sayward. 1978. Hints on Test Data Selection: Help for the Practicing Programmer. Computer 11, 4 (April 1978), 34-41
In their paper they cite Hoare's Find algorithm and how random testing and permutation-based techniques come short in detecting mutants. They also
have a set of magic numbers that they claim it perform great. Here I want to reproduce the results and see what those tests have that exhausitive 
permutation testing and heavy random testing cannot find.
*/

#include "util.c"

void find(int* A, int F, int N){
  int M = 0, NS = 0, R = 0, I = 0, J = 0,W = 0;
  /* NOTE: A[0] is a dummy element to keep the code consistent with 
     the original code.
   */
  N = N -1;
  M = 1;
  NS = N;
  
 l10: if(M >= NS)
    goto l1000;
  R = A[F];
  I = M;
  J = NS;
 l20: if (I > J) goto l60;
 l30: if (A[I] >= R) goto l40;
  I = I + 1;
  goto l30;
 l40: if (R >= A[J]) goto l50;
  J = J - 1;
  goto l40;
 l50: if (I > J) goto l20;
  W = A[I];
  A[I] = A[J];
  A[J] = W;
  I = I + 1;
  J = J - 1;
  goto l20;
 l60: if (F > J) goto l70;
  NS = J;
  goto l10;
 l70: if (I > F) goto l1000;
  M = I;
  goto l10;
 l1000:
  return;
}
