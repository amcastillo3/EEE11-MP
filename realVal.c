#include <stdio.h>
#include <math.h>
#include "apVal.h"

float realVal(float range[2],float coeff[4], float apSumm){
		
	float Aupper; 
	float Alower;
	float Real; 
	float errorC;
	
	Aupper = (coeff[0] * pow(range[1],4))/4 + (coeff [1] * pow(range[1],3))/3 + (coeff[2] * pow(range[1],2))/2 + (coeff[3] * range[1]);
	Alower = (coeff[0] * pow(range[0],4))/4 + (coeff[1] * pow(range[0],3))/3 + (coeff[2] * pow(range[0],2))/2 + (coeff[3] * range[0]);
	
	Real = Aupper - Alower;
	errorC = (100-(((Real - apSumm)/Real)*100))*100;
	
	printf("Real value = %.2f\n",Real);
	printf("Percent error: %f\n",errorC);
	
	return 0;
}

