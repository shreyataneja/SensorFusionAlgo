#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#include "../include/fusion_contribution_rate.h"

/* Calculate the principal components of the support degree matrix and their eigen vectors.*/
	void calc_principal_component  (int size,double *arr_eigenvalue,double **arr_eigenvector,double **degreematrix,sensor *sensor_data){
		int i,j;	
		double **principal_component = (double **)malloc(size * sizeof(double *));
		for (i=0; i<size; i++){ 
			principal_component[i] = (double *)malloc(size * sizeof(double)); 
		}
		 double sum;
			for(int k=0;k<size;k++)
				for (i = 0;  i < size; i++){
					for (j = 0; j < size; j++){					
						principal_component[k][i] += arr_eigenvector [k][j] * degreematrix [i][j];;						
						}
			}
			
		cal_contribution_rate(arr_eigenvalue,principal_component,sensor_data,size);
}

