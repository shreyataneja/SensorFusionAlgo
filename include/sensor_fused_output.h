
#ifndef __SENSOR_FUSED_OUTPUT_H__
#define __SENSOR_FUSED_OUTPUT_H__
#include "sensorstructure.h"


void valid_fused_output(int counter_outof_range[],int size_eliminated,double weight_coefficient[],sensor sensor_data[],int size);

#endif // __SENSOR_FUSED_OUTPUT_H__