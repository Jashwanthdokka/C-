#include <stdlib.h>
#include <math.h>
#define n 4
float A[n+1][n+1];
float B[n+1];
float x[n+1];
float pipechan[n+2];

int i;
int j;
void PipeProcess(int i) {
    /* Solves Equation i to compute x[i] */
    float sum, xvalue;
    sum = 0;
    for (j = 1; j <= i-1; j++) {
        xvalue = pipechan[i]; /* Read x[j] from the left */
        pipechan[i+1] = xvalue; /* Send x[j] to the right */
        sum = sum + A[i][j] * xvalue;
    }
    x[i] = (B[i] - sum) / A[i][i]; /* Compute x[i] */
    pipechan[i+1] = x[i]; /* Send x[i] to the right*/
}

int main() {
    /* Initialize array A with coefficients*/
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            /* Assign coefficients for the system of equations*/
            A[i][j] = 1.0 / (i + j);
        }
    }

    /* Initialize array B with right-hand side values*/
    for (i = 1; i <= n; i++) {
        /* Assign right-hand side values for the equations*/
        B[i] = 2.0 / i;
    }

    /* Create pipeline processes*/
    for (i = 1; i <= n; i++) {
        PipeProcess(i);
    }

    /* At this point, the x array contains the solutions to the system of equations*/

    /* You can print the solutions if needed*/
    cout << "Solutions (x array):" << endl;
    for (i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}
