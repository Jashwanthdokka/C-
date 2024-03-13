#include <stdlib.h>
int i;
float n, fact = 1;

main() 
{
cin>>n;
	for(i=1; i<=n; i++)
	{
		fact *= i;
	}
cout.precision(12);
	cout<< "The Factorial of" <<n<< "=" <<fact;
}