#include <stdlib.h>
#include <math.h>
int sum = 0;  
int i;
int main()
{
    for (i = 1; i <= 100; i++) /* A loop to sum up integers from 1 to 100 */
	{
        sum += i;
   	}
    cout <<sum<< endl; 
}
