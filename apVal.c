#include <stdio.h>
#include <math.h>

float apVal(float range[2],float coeff[4],float delta){
	
	float sum = 0; 
	float i = 0;
	float j = 0;
	float apSumm = 0;
	
	for( ; i <= range[1] ; i = i + delta){
		j = coeff[0] * pow(i,3) + coeff[1] * pow(i,2) + (coeff[2] * i) + coeff[3];
		sum = delta*j;
		apSumm = apSumm + sum;
	}
		printf("Approximated Value: %f\n",apSumm);
		return apSumm;
}	
