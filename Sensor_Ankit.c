#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "gsl/gsl_matrix.h"
//#include "gsl/gsl_vector.h"

//#include "gsl/gsl_eigen.h"
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_eigen.h>

#define LSIZ 128
#define RSIZ 100
//void step3	(int,double [],double [][size]);
struct sensor{
char time[50];
char sens_name[50];
double val;
};

void cal_integrated_support_degree(double contribution_rate[],double * principal_component,int size){
	double r [size][size];
    double integrated_support_degree[size] = {0};
    int i,j;
    double sum_integrated_support_degree = 0;
     for(i = 0; i < size;i++)
    {
        for (j=0; j< size; j++)
        {
        	 
        	r[i][j]=(*((principal_component+i*size) + j))* contribution_rate[i];
           
		
           
           printf("i:%d uhiushiush:%lf\n",i,r[i][j]);
        }
       
    }
    
 //   for(i = 0;i<size;i++){
   //    	integrated_support_degree[i]=r[i] ;
     //  	 printf(" integrated_support_degree is %lf\n",integrated_support_degree[i]);
	//}
	

	
   for(i = 0;i<size;i++){
       sum_integrated_support_degree = sum_integrated_support_degree + r[0][i];
	}
      printf(" sum integrated_support_degree: %lg \t\n", sum_integrated_support_degree);
     printf(" mean integrated_support_degree: %lg \t\n", sum_integrated_support_degree/size);
	//for(r = 0;r<size;r++){
      //  integrated_support_degree[r] = principal_component[r] * contribution_rate[r];
       // printf("integrated_support_degree: %lg \n", integrated_support_degree[r]);
	//}
  //  
  //  for(r = 0;r<size;r++){
   //     sum_integrated_support_degree = sum_integrated_support_degree + integrated_support_degree[r];
	//}
    
 
    double X_Thresh ; 
    
    X_Thresh = (sum_integrated_support_degree/size)*(0.7);
    printf(" Threshold: %lf \t\n", X_Thresh);
   // printf(" Size: %d \t\n", size);
    
    
    
	
}	


void cal_contribution_rate(double arr_eigenvalue[],double * principal_component,int size){
	double contribution_rate[size] ={0};
    int r,c;
    double egval_sum = 0;
    for(c = 0;c<size;c++){
        egval_sum = egval_sum + arr_eigenvalue[c];
        
	}
	//printf("egval_sum final : %g \t\n	",egval_sum);
    for(r = 0;r<size;r++){	
   // printf(" Eigen Values %g \t\n",arr_eigenvalue[r]);
   // printf("egval_sum : %g \t\n	",egval_sum);
    	double s = 0;
    	s = arr_eigenvalue[r];
    	contribution_rate[r] =  (s)/(egval_sum);
        printf("contribution_rate\t: %lg\n", contribution_rate[r]);
	}
    double sum_contribution_rate = 0;
    for(r = 0;r<size;r++){
      sum_contribution_rate = sum_contribution_rate+contribution_rate[r];
      printf("sum_contribution_rate\t: %lg\n", sum_contribution_rate);
	}
	
cal_integrated_support_degree(contribution_rate, (double *)principal_component, size);
}
void step3	(int size,double arr_eigenvalue[],double *arr_eigenvector,double *dij)
{ int i,j;
//printf("in function step3\n");
//	  printf("Array of eigen value is here ");
//	  for (i = 0; i < size; i++)
//	  { printf("%g\t",arr_eigenvalue[i]);
	  	 
//	  }

 double principal_component[size][size]={0};
 double sum;
  double x,y;
  	  for(int k=0;k<size;k++)
  for (i = 0;  i < size; i++){
	for (j = 0; j < size; j++)
   {
   	x=*((arr_eigenvector+k*size) + j);
   y=*((dij+i*size) + j);
   principal_component[k][i] += x*y;
 //printf("\n Eigenvalue= \  %g\t\n",arr_eigenvalue[j]);
  // printf("\n EigenVector=  %d, %d   %g\t\n", k,j,x);
  
	}

}
for (i = 0;  i < size; i++){
	for (j = 0; j < size; j++)
   {
 printf("Principal compnent %d    %d :  %g\t",i,j, principal_component[i][j]);
 printf("\n");
}}
cal_contribution_rate(arr_eigenvalue,(double *)principal_component,size);
}


   
void support_degree(struct sensor arr[],int size)
{
	 int i,j;

    double dij[size][size];
	double sum_D[size] = {0};
    for(i = 0; i < size;i++)
    {
        for (j=0; j< size; j++)
        {
            double d =abs(arr[i].val - arr[j].val);
        //   printf(" d is %lf\n",d);
            dij[i][j] = exp(-d);
        //    printf("i:%d j:%d dij:%lf\n",i,j,dij[i][j]);
        }
    }
    
    for(i = 0; i < size;i++)
    {
        for (j=0; j< size; j++)
        {
             sum_D[i] =  sum_D[i] + dij[j][i];
           
          //  printf("i:%d j:%d dij:%lf\n",i,j,dij[i][j]);
        }
     //   printf(" sum_D is %lf\n",sum_D[i]);
    }
    

//printf("size of struct  is : %d\n",size);
//for(i=0;i<size;i++)
//{	printf("in struct time of sensor is %s\n",arr[i].time);
//	printf("in struct name of sensor is %s\n",arr[i].sens_name);
//	printf("in struct value of sensor is %f\n",arr[i].val);
//}
double data[size*size];
int k=0;

 for(i = 0; i < size;i++)
    {
        for (j=0; j< size; j++)
        {	data[k++]=dij[i][j];
		//	printf("data %lf",data[--k]);
        //   printf("i:%d j:%d dij:%lf\n",i,j,dij[i][j]);
        }
    } 
gsl_matrix_view m   = gsl_matrix_view_array(data, size, size);

  gsl_vector *eval = gsl_vector_alloc (size);
  gsl_matrix *evec = gsl_matrix_alloc (size, size);

  gsl_eigen_symmv_workspace *w =  gsl_eigen_symmv_alloc (size);
  
  gsl_eigen_symmv (&m.matrix, eval, evec, w);

  gsl_eigen_symmv_free(w);

  gsl_eigen_symmv_sort (eval, evec, 
                        GSL_EIGEN_SORT_ABS_DESC);
  
  
   double arr_eigenvalue[size];
   double arr_eigenvector[size][size];
//printf("%d\n",size);
    for (i = 0; i < size; i++)
      {
        double eval_i = gsl_vector_get(eval, i);
        
        gsl_vector_view evec_i = gsl_matrix_column(evec, i);
		arr_eigenvalue[i]=eval_i;
        printf("eigenvalue = %g\n", eval_i);
       printf("eigenvector = \n");
       gsl_vector_fprintf(stdout,&evec_i.vector, "%g");
       for (j = 0; j < size; j++)
       arr_eigenvector[i][j] = gsl_vector_get(&evec_i.vector,j);
    //\\ printf("""""""""""""""""""""""""""""""\n%g\n",gsl_vector_get(&evec_i.vector,j)) ;
	  }

  step3(size,arr_eigenvalue,(double *)arr_eigenvector,(double *)dij);
  
}


int main(void)
{
    char line[RSIZ][LSIZ];
	char line_temp[RSIZ][LSIZ];
	char fname[20];
	struct sensor sen_val[500];
    FILE *fptr = NULL;
    int i = 0,j=0,k=0,k1=0;
    int tot = 0,count=0;
   	// printf("\n\n Read the file and store the lines into an array :\n");
	//	printf(" Input the filename to be opened : ");
	// scanf("%s",fname);

    fptr = fopen("abc.csv", "r");
    while(fgets(line[i], LSIZ, fptr))
{
    	    line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    char timezone[50];
	strcpy(timezone,line[0]);
	strtok(timezone, ",");
    tot = i;
    printf("val of tot :%d",tot);
	printf("\n The content of the file %s  are : \n",fname); 
	while(j<tot)
		{		char temp2[50] ;
	    strcpy(temp2,line[j]);
    	strtok(temp2, ",");
  	 	
	if (strcmp (timezone,temp2)==0)
		{	 k=0;
   			 for(i = count; i < tot; i++)
			    {	char temp[50] ;
    				strcpy(temp,line[i]);
    				strtok(temp, ",");
  	 	 
		if (strcmp (timezone,temp)==0)
		{	
	     // printf(" %s\n", line[i]);
	     
	       //strcpy(line_temp[k++],line[i]);
	       	 char* token = strtok(line[i], ",");
	      
	        strcpy(sen_val[k].time, token) ;
	        token = strtok(NULL, ",") ;
	        strcpy(sen_val[k].sens_name, token) ;
	        token = strtok(NULL, "\n") ;
	        sen_val[k].val = atof(token) ;
	       k++;
		   count++;
	    }
        else
        {
        	strcpy(timezone,line[i]);
			strtok(timezone, ",");
        	break;
		} 

	}
	support_degree(sen_val,k);
	  printf("\n");
}
j=i;
}
    return 0;
}


