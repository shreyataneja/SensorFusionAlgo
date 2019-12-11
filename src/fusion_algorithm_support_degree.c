#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 
#include "../include/fusion_eign_value_vector_generation.h"

void support_degree(sensor sensor_data[],int size){ 			/*This function is to calculate the Support Degree Matrix*/
	int i,j;    														
	double **degreematrix ;									/*initialize 2-D array to deduce the support degree matrix*/
	degreematrix = (double **)malloc(sizeof(double *) * size); 

    for (i=0; i<size; i++){ 
         degreematrix[i] = (double *)malloc( sizeof(double) * size); 
	}
    for(i = 0; i < size;i++){
        for (j=0; j< size; j++){
            double d =abs(sensor_data[i].value - sensor_data[j].value);       
            degreematrix[i][j] = exp(-d);       
        }
    }
   eign_value_vector_generation(degreematrix,sensor_data,size);
   
}
   
