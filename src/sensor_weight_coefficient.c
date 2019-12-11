/* Compute the weight coefficient for each non eliminated sensor*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "../include/sensor_fused_output.h"


void calc_weight_coefficient(int counter_outof_range[],int size_eliminated,double integrated_support_degree[],double sum_integrated_support_degree,sensor sensor_data[],int size){
int i,k;
double *weight_coefficient = (double *)malloc(size * sizeof(double));
for(i=0;i<size;i++)
{	for(k=0;k<size_eliminated;k++)
	{
	if(i != counter_outof_range[k])
	weight_coefficient[i]=integrated_support_degree[i]/sum_integrated_support_degree;	
	
	}

}
valid_fused_output(counter_outof_range,size_eliminated,weight_coefficient, sensor_data,size);
}

