#include<stdio.h>
#include<math.h>
#include<string.h>


double weightcoefficient(int counter_outof_range[],int size_eliminated,double integrated_support_degree[],double sum_integrated_support_degree,int size){
		int i,k;
	double weight_coefficient[size];
	double sum_weight=0;
	for(i=0;i<size;i++){
		for(k=0;k<size_eliminated;k++){
			if(i != counter_outof_range[k]){
				weight_coefficient[i]=integrated_support_degree[i]/sum_integrated_support_degree;
				sum_weight=sum_weight+	weight_coefficient[i];	
			}
		}
	}

	return sum_weight;
}


double calc_threshold(double *integrated_support_degree , double sum_integrated_support_degree,int size){
	int i;
 	double X_Thresh ;
	X_Thresh = abs(sum_integrated_support_degree/size)*(0.7);	
	return X_Thresh;
}

int read_file(char * filename){
	int i;
	char line[128][128];
		FILE *fptr = NULL;
		if((fptr = fopen(filename, "r"))==NULL){					
			printf("Cannot open file.\n");
  		}
		else{
		while(fgets(line[i], 128, fptr)){
		line[i][strlen(line[i]) - 1] = '\0';
		i++;
		}
		}
	return i;
}

int detect_out_of_range_sensor(double *integrated_support_degree,double sum_integrated_support_degree,int size,double X_Thresh){
	int *counter_outof_range = (int *)malloc(size * sizeof(int));
	int i;
	int size_eliminated=0;
	for(i=0;i<size;i++){
		if(abs(integrated_support_degree[i])<X_Thresh){
			counter_outof_range[size_eliminated++]=i;
		}
		else
		continue;
	}
	return size_eliminated;	
}


int valid_fused_output(int *counter_outof_range,int size_eliminated,double *weight_coefficient,double *sensor_data,int size){
	int i,r;
	double fused_output=0;	
	for(i=0;i<size;i++){	
		fused_output += weight_coefficient[i] * sensor_data[i];
	}
		return i;	                                       
}
