#include <stdlib.h>
#include <math.h>
#define n 100 /* n: the upper limit of the range of numbers to check*/
#define l 2 /*l: the number of processes to create */
#define m 100 /* m: the size of each segment of numbers */
boolean Prime[11][101]; 
int i, j, k, num, loc, s, t; 
int stream commchan[11]; /* common channel for each process */
#define endmarker -1 
void primeProcess(int processID) 
{
 int p = 1; /* the prime number from process 0, initialized with dummy value 1 */
 int c; /* first index or a multiple of p in Prime[processID][] */
int startInt = (processID-1)*m + 1; /* integer corresponding to 
Prime[processID][1] */
 int s; 
 recv(commchan[processID], p); /*Read next prime number p from stream*/ 
 while (p != endmarker) {
c = 1;
s = startInt;
while (((s % p) != 0) && (c < m)) {
 s++; c++;
}
while (c <= m) {
 Prime[processID][c] = FALSE;
 c += p;
}
 recv(commchan[processID], p); /*Read next prime from stream*/
 } 
}
main( ) {
 /* mark all integers from 1 to 200 as prime */
 for (i = 1; i <= l; i++)
for (j = 1; j <= m; j++) /* isPrime(k) is stored in Prime[(k/m)+1][(k % m)+1] */
 Prime[i][j] = TRUE; 
for (i = 2; i <= l; i++)
 fork primeProcess(i); 
 for (num = 2; num <= sqrt(n); num++)
 if (Prime[1][num]) {
 for (k = 2; k <= l; k++)
send(commchan[k], num); /* each process do the following 5 lines of code in parallel */
 loc = num + num;
 while (loc <= m) {
 Prime[1][loc] = False;
 loc = loc + num;
 } 
} 
 for (i = 2; i <= l; i++) send(commchan[i], endmarker); /* to terminate all primeProcess */
 for (i = 2; i <= l; i++) join; /* wait for all l-1 primeProcess processes to finish */
 cout << "Prime numbers are: " << endl;
 for (i = 2; i <= 100; i++) { 
s = ((i-1) / m) + 1;
t = ((i-1) % m) + 1; 
 if (Prime[s][t]) cout << i << ", " << endl;
 }
}

