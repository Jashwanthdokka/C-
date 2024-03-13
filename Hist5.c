#define n 20 /*dimension of the image*/
#define max 10 /*maximum pixel intensity*/
int image[n+1][n+1];
int hist[max+1];
spinlock L[max+1];
int i;
main( ) {
 /*Initialize the image array*/
for (i = 0; i <= max; i++)
hist[i] = 0;
forall i = 1 to n do {
int j, intensity;
for (j = 1; j <= n; j++) {
intensity = image[i][j];
Lock(L[intensity]);
hist[intensity] = hist[intensity] + 1;
Unlock(L[intensity]);
}
}
}

