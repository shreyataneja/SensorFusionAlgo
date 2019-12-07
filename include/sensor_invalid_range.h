
#ifndef __SENSOR_INVALID_RANGE_H__
#define __SENSOR_INVALID_RANGE_H__
#include "sensorstructure.h"

void detect_out_of_range_sensor(double integrated_support_degree[],double sum_integrated_support_degree,sensor sensor_data[],int size,double X_Thresh);
void calc_weight_coefficient(int counter_outof_range[],double integrated_support_degree[],double sum_integrated_support_degree,sensor sensor_data[],int size,int size_eliminated);
void valid_fused_output(double weight_coefficient[],sensor sensor_data[],int size);


#endif // __SENSOR_INVALID_RANGE_H__
