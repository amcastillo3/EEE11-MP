#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "apVal.h"
#include "realVal.h"

int main(int argc, char **argv)
{
	char buff[1024];
    	int count;
    	int checkr = 0, checkc = 0;
    	float delta = 0.001, coeff[4], range[2];

	for(count = 1; count < argc; count++){
		if(!strcmp("-c", argv[count])){
			if(count + 1 >= argc){
				printf("No argument for -c\n");
				return 0;
			}
			strcpy(buff, argv[++count]);
			coeff[0] = atof(strtok(buff, ","));
			coeff[1] = atof(strtok(NULL, ","));
			coeff[2] = atof(strtok(NULL, ","));
			coeff[3] = atof(strtok(NULL, ","));
			checkc = 1;
		}
		else if(!strcmp("-r", argv[count])){
			if(count + 1>= argc){
				printf("No argument for -r.\n");
				return 0;
		}
		strcpy(buff,argv[++count]);
		range[0] = atof(strtok(buff, ",")); 
		range[1] = atof(strtok(NULL, ","));
		checkr = 1;
		}
		else if(!strcmp("-d", argv[count])){
			count++;
			if(count >= argc){
				printf("No argument for -d.\n");
				return 0;
			}
			strcpy(buff,argv[count]);
			delta = atof(buff);
		}
		else{
			printf("Unknown option '%s'.. \n", argv[count]);
			return 0;
		}
	}
	if((checkr = 0) || (checkc = 0)){
		printf("Missing operands\n");
		return 0;
	}	
	apVal(range,coeff,delta);
	realVal(range,coeff,delta);
	return 0;
}
