#include <math.h>
#define n 32
#define tolerance .01
float A[n+2][n+2], B[n+2][n+2];
int i,j;
float change, maxchange;
void Barrier(int me) {
... /*same as before*/ }
boolean Aggregate(boolean mydone) {
... /*see Figure 6.14*/ }
main( ){
... /*Read in initial values for array A*/
B = A;
forall i = 1 to n do { /*Create the processes*/
int j;
float change, maxchange;
boolean done;
do {
maxchange = 0;
for (j = 1; j <= n; j++) {
/*compute new value for each point in my row*/
B[i][j] = (A[i-1][j] + A[i+1][j] +
A[i][j-1] + A[i][j+1]) / 4;
change = fabs( B[i][j] - A[i][j] );
if (change > maxchange) maxchange = change;
}
Barrier;
A[i] = B[i];
done = Aggregate(maxchange<tolerance);
}while (!done); /*iterate until global termination*/
}
}

