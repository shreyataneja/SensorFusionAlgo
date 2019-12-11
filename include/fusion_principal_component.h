#ifndef __FUSION_PRINCIPAL_COMPONENT_H__
#define __FUSION_PRINCIPAL_COMPONENT_H__
#include "sensorstructure.h"


void calc_principal_component (int size,double arr_eigenvalue[],double **arr_eigenvector,double **degreematrix,sensor sensor_data[]);

#endif // __FUSION_PRINCIPAL_COMPONENT_H__