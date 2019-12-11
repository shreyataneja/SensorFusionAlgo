#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_eigen.h>

 
#include "../include/fusion_principal_component.h"
  
/*This function is to calculate the eigen values and eigen vectors from Support Degree Matrix*/   
void eign_value_vector_generation(double **degreematrix,sensor sensor_data[], int size){
	int sizeforarray = size*size;
	double *data=(double *)malloc(sizeforarray * sizeof(double));
	int i=0 , j=0 , k=0;
	for(i = 0; i < size;i++){
        for (j=0; j< size; j++){ 
		data[k++]= degreematrix[i][j];
        }
    }
	gsl_matrix_view m   = gsl_matrix_view_array(data, size, size);
	gsl_vector *eval = gsl_vector_alloc (size);
	gsl_matrix *evec = gsl_matrix_alloc (size, size);
	gsl_eigen_symmv_workspace *w =  gsl_eigen_symmv_alloc (size);
	gsl_eigen_symmv (&m.matrix, eval, evec, w);
	gsl_eigen_symmv_free(w);
	gsl_eigen_symmv_sort (eval, evec,GSL_EIGEN_SORT_ABS_DESC);	 
	   double *arr_eigenvalue = (double *)malloc( (size) * sizeof(double));
	   double **arr_eigenvector = (double **)malloc(size * sizeof(double *)); 	
		for (i=0; i<size; i++){
			arr_eigenvector[i] = (double *)malloc(size * sizeof(double));
		}			 

		for (i = 0; i < size; i++){
			double eval_i = gsl_vector_get(eval, i);		   
			gsl_vector_view evec_i = gsl_matrix_column(evec, i);
			arr_eigenvalue[i]=eval_i;
		   for (j = 0; j < size; j++){
				arr_eigenvector[i][j] = gsl_vector_get(&evec_i.vector,j);
		   }
		}
	calc_principal_component (size,arr_eigenvalue,arr_eigenvector,degreematrix,sensor_data);
}

