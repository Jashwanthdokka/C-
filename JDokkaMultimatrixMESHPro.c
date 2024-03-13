ARCHITECTURE TORUS(7); /* Declares an architecture named "TORUS" with a grid size of 7x7 processors.J_Dokka*/
#include <stdlib.h>
#define m 7
#define p 5 /* Defines macros m and p with values 7 and 5, representing the size of the torus grid and the partition size, respectively.J_Dokka*/
typedef float partition[p+1][p+1]; /* Defines a 2D array type named partition with dimensions (p+1) x (p+1) to store float numbers.J_Dokka*/
partition A[m][m], B[m][m], C[m][m]; 
partition stream Achan[m][m], stream Bchan[m][m]; /* Declares three 2D arrays of type partition named A, B, and C to store matrices, and two streams of type partition named Achan and Bchan for communication.J_Dokka*/
int i,j; /* declare variables J_Dokka*/
/* Declares a function Multiply that takes row and column indices, two partitions myA and myB, and a main result partition mainC as parameters.J_Dokka*/
void Multiply(int row, int col, value partition myA, value partition myB, partition mainC)
{
  int i,j,k,iter,above,left; /* Declares variables i, j, k, iter, above, and left, and initializes a partition myC with zeros.J_Dokka*/
  partition myC = {0};
  if (row > 0) above = row-1;
    else above = m-1;
  if (col > 0) left = col-1;
    else left = m-1; /* Calculates the indices of processors above and to the left in the torus grid, considering wrap-around for the top and left edges.J_Dokka*/
  for (iter = 1; iter <= m; iter++) /* Starts a loop for m iterations. J_Dokka*/{
    send(Achan[row][left], myA);
	  send(Bchan[above][col], myB); /* Sends partitions myA and myB to the left and above processors, respectively.J_Dokka*/

	  for (i = 1; i <= p; i++)
	   for (j = 1; j <= p; j++)
		  for (k = 1; k <= p; k++) /* Performs matrix multiplication on partitions myA and myB, adding the result to partition myC.J_Dokka*/
		    myC[i][j] = myC[i][j] + myA[i][k] * myB[k][j];
	  recv(Achan[row][col], myA);
	  recv(Bchan[row][col], myB);
  }
  mainC = myC;
} /* Receives new partitions myA and myB after the computation loop and updates the main result partition mainC.J_Dokka*/

main( ) {

  int k, l;
  for (i = 0; i < m; i++)
	 for (j = 0; j < m; j++)
	  for (k = 1; k <= p; k++)
	    for (l = 1; l <= p; l++) {
		    A[i][j][k][l] = (rand() % 100)/10.0;
		    B[i][j][k][l] = (rand() % 100)/10.0;
	     } /* Initializes matrices A and B with random float values between 0 and 10.J_Dokka*/

  for (i = 0; i < m; i++)
	 for (j = 0; j < m; j++)
	  fork (@i * m + j)
      Multiply(i, j, A[i][(j+i)%m], B[(i+j)%m][j], C[i][j]); /* Creates parallel processes using a nested loop and fork to execute the Multiply function with specific parameters for each process.J_Dokka*/

  for (i = 0; i < m; i++)
	 for (j = 0; j < m; j++)
	  join; /* Waits for all parallel Multiply processes to finish before continuing with the rest of the execution.J_Dokka*/

  cout.precision(4);
  for (i = 0; i < m; i++) {
	 for (j = 0; j < m; j++) {
	  cout << "partition[" << i << ", " << j << "]" << endl;
	  for (k = 1; k <= p; k++) {
		 for (l = 1; l <= p; l++)
		  cout << C[i][j][k][l] << ", ";
	    cout << endl;
	  }
	 }
  }
} /* Sets the precision for floating-point output to 4 significant digits and prints the resulting matrix C. J_Dokka*/
