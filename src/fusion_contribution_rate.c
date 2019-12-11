#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 
#include "../include/fusion_integrated_sd.h"

 
/*Calculate the contribution rate of the kth principal component.*/
void cal_contribution_rate(double arr_eigenvalue[],double ** principal_component,sensor sensor_data[],int size){
		double *contribution_rate = (double *)malloc( (size) * sizeof(double));
			double *sum_contribution_rate =  (double *)malloc( (size) * sizeof(double));
			int r,c;
			double egval_sum = 0;
			for(c = 0;c<size;c++){
				egval_sum = egval_sum + arr_eigenvalue[c];			   
			}			
			for(r = 0;r<size;r++){			
			double s = 0;
			s = arr_eigenvalue[r];
			contribution_rate[r] =  (s)/(egval_sum);
				printf("contribution_rate\t: %lg\n", contribution_rate[r]);
			}
			double sum=0;
			for(r = 0;r<size;r++){
				sum += contribution_rate[r];
			  sum_contribution_rate[r] = sum ;
			  
			  printf("sum_contribution_rate\t: %lg\n", sum_contribution_rate[r]);
			}
	cal_integrated_support_degree(contribution_rate,sum_contribution_rate, principal_component,sensor_data, size);
}


