#include "new_max.h"


int max(int counter_outof_range[],int size_eliminated,double integrated_support_degree[],double sum_integrated_support_degree,int size){
	int i,k;
	//double *weight_coefficient = (double *)malloc(size * sizeof(double));
	double weight_coefficient[size];
	for(i=0;i<size;i++){
		for(k=0;k<size_eliminated;k++){
			if(i != counter_outof_range[k]){
				weight_coefficient[i]=integrated_support_degree[i]/sum_integrated_support_degree;	
			}
		}
	}
	return size;
	
}