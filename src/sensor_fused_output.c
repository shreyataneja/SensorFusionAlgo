/*Compute the fused output*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/file_operations.h"

void valid_fused_output(int counter_outof_range[],int size_eliminated,double weight_coefficient[],sensor sensor_data[],int size){
	int i;
	static int itr=0;
	double fused_output;
	for(i=0;i<size;i++){	
		fused_output += weight_coefficient[i] * sensor_data[i].value;
	}
		itr++;
	write_to_output_file(counter_outof_range,size_eliminated,sensor_data,fused_output,size,itr);                                       
}


