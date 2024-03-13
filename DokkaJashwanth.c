/* PROGRAM NumericalIntegration */
#include <stdlib.h>  
#include <math.h>
#define numprocesses 40 /*number of processes*/
#define nump1 30 /*number of points per process*/
float a,b,w,globalsum,ans;
int i;
spinlock L;
float f(float t) /*Function to be integrated*/
{
	return( sqrt(4 - t*t) ); /*as per the instructions computing the value of f(t)*/
}
void Integrate(int myindex)
{
	float localsum = 0,t;
	int j;
	t = a + myindex*(b-a)/numprocesses; /*My start position*/
	for (j = 1; j <= nump1; j++) 
	{
		localsum = localsum + f(t); /*Add next point*/
		t = t + w;
	}
	localsum = w * localsum;
	Lock(L);
	globalsum = globalsum+localsum; /*atomic update*/
	Unlock(L);
}
main( )
{
	int a = 0 ,b = 2; /*Initialize values of end points “a” and “b”*/
	w = (b-a)/(numprocesses*nump1); /*spacing of points*/
	forall i = 0 to numprocesses*nump1-1 do /*Create processes*/
	Integrate(i);
	ans = globalsum + w/2*(f(b)-f(a)); /*end points*/
}

