#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 
#include "../include/fusion_threshold.h"

/* Compute the integrated support degree score for all sensors*/
void cal_integrated_support_degree(double *contribution_rate, double *sum_contribution_rate,double ** principal_component,sensor *sensor_data,int size){
	
	double integrated_support_degree[size]; 
	double sum_integrated_support_degree;
	int counter;
	int i,j;
	for(i=0;i<size;i++){
		if(sum_contribution_rate[i]*100 <=85)
		counter ++;
		else
		break;
	}
    double **calc_integrated_support =  (double **)malloc(size * sizeof(double *));
	for (i=0; i<size; i++){ 
			calc_integrated_support[i] = (double *)malloc(size * sizeof(double)); 
	}
    for(i = 0; i < counter;i++){
        for (j=0; j< size; j++){       
			calc_integrated_support[i][j] = principal_component[i][j] * contribution_rate[i];			
        }   
    }   
	double sum;
    for(i = 0; i < size;i++){
		sum = 0;
        for (j=0; j< counter; j++){       
        sum += calc_integrated_support[j][i];       
        }
    	integrated_support_degree[i]=sum;
	} 
 	for(i=0;i<size;i++){
 	 	sum_integrated_support_degree +=integrated_support_degree[i];
	}
 	
	calc_threshold(integrated_support_degree,sum_integrated_support_degree,sensor_data,size);
}

