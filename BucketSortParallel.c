#include <stdlib.h>  
#include <math.h>

#define n 10
#define m 100  
#define bucket_number 10 

int data[n+1], sortedData[n+1]; 
int bucket[bucket_number][n+1]; 
int i, j;
void sort(int d[]) {
  int m = d[0]; 
  int j, k, max, max_index, temp;
  for (j = m; j > 1; j--) {
    max = d[j];
	  max_index = j;
    for (k = 1; k < j; k++) {
      if (d[k] > max) {
	    max = d[k];
		max_index = k;
	  }
	}
	temp = d[j];
	d[j] = max;
	d[max_index] = temp;
  }

  
}

main() {
 for (i = 1; i <= n; i++) 
	  data[i] = rand() % m;

  forall i = 1 to n do {
    int v = data[i];
	  int b_i = v/10; 
	  int i = ++bucket[b_i][0]; 
	  bucket[b_i][i] = v;
  }

  forall i = 0 to 9 do {
    sort(bucket[i]);
  }
  
  int k = 1;
  for (i = 0; i <= 9; i++){ 
    for (j = 1; j < bucket[i][0]; j++) { 
      sortedData[k++] = bucket[i][j];
    }
  }

  k--;
  for (i = 1; i <= k; i++)
	  cout << "d[" << i << "]=" << sortedData[i] << endl;  
}