
#ifndef __SENSOR_WEIGHT_COEFFICIENT_H__
#define __SENSOR_WEIGHT_COEFFICIENT_H__
#include "sensorstructure.h"


void calc_weight_coefficient(int counter_outof_range[],int size_eliminated,double integrated_support_degree[],double sum_integrated_support_degree,sensor sensor_data[],int size);

#endif // __SENSOR_WEIGHT_COEFFICIENT_H__