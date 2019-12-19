#ifndef TEST_SENSOR_FUSION
#define TEST_SENSOR_FUSION


extern double weightcoefficient (int counter_outof_range[],int size_eliminated,double integrated_support_degree[],double sum_integrated_support_degree,int size);
extern double calc_threshold(double *integrated_support_degree , double sum_integrated_support_degree,int size);
extern int read_file(char * filename);
extern int detect_out_of_range_sensor(double *integrated_support_degree,double sum_integrated_support_degree,int size,double X_Thresh);
extern int valid_fused_output(int *counter_outof_range,int size_eliminated,double *weight_coefficient,double *sensor_data,int size);

#endif //TEST_SENSOR_FUSION