/*Calculate the threshhold from all the sensors*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../include/sensor_invalid_range.h"
void calc_threshold(double *integrated_support_degree , double sum_integrated_support_degree,sensor *sensor_data,int size){
	
 	double X_Thresh ;
	X_Thresh = abs(sum_integrated_support_degree/size)*(0.7);	
	
	detect_out_of_range_sensor(integrated_support_degree,sum_integrated_support_degree,sensor_data,size,X_Thresh);
}


