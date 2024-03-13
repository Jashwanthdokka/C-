#include <stdlib.h>
#include <math.h>

int sum = 0;  
int i;

int main() {
    /*Loop from 1 to 100 and add each number to the sum*/
    for (i = 1; i <= 100; i++) 
	{
        sum += i;
   	 }

    /* Print the sum */
    cout <<sum<< endl;
}
