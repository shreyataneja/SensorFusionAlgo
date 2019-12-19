
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../include/test_sensor_fusion.h"
#include <stdio.h>  // for printf

/**
	* Test Suite setup and cleanup functions: 
*/


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/**
*********** Test case functions ***************
*/

void weightcoefficient_test_1(void) {
	int counter_outof_range[] = {2,6};
	double integrated_support_degree[] = {1.22162, 0.957269, 0.441635, 1.22162, 1.07867, 1.14837, 0.441635, -1.20587};
	CU_ASSERT( weightcoefficient(counter_outof_range,2,integrated_support_degree, -8.20912327, 8)>=-1.184856);
	CU_ASSERT( weightcoefficient(counter_outof_range,2,integrated_support_degree, -8.20912327, 8)>=-1.184856);
}



void calc_threshold_test_1(void) {
	double integrated_support_degree[] = {1.22162, 0.957269, 0.441635, 1.22162, 1.07867, 1.14837, 0.441635, -1.20587};
	CU_ASSERT( calc_threshold(integrated_support_degree, -8.20912327, 8)>=0.718298);
	CU_ASSERT( calc_threshold(integrated_support_degree, -8.20912327, 8)>=0.718298);	
}

void read_file_test_1(void) {
 char filename[50] = "../test__1.csv";
	CU_ASSERT_EQUAL( read_file(filename),17);
	CU_ASSERT_EQUAL( read_file(filename),17);
}

void detect_out_of_range_sensor_test_1(void) {
	double integrated_support_degree[] = {1.22162, 0.957269, 0.441635, 1.22162, 1.07867, 1.14837, 0.441635, -1.20587};
	CU_ASSERT_EQUAL( detect_out_of_range_sensor(integrated_support_degree, -8.20912327, 8,0.718298),2);
	CU_ASSERT_EQUAL( detect_out_of_range_sensor(integrated_support_degree, -8.20912327, 8,0.718298),2);
}

void valid_fused_output_test_1(void) {
	int counter_outof_range[] = {2,6};
	double weight_coeff[]={-0.148812,-0.116610,-0.053798,-0.148812,-0.131399,-0.139889,-0.053798,0.146894};
	double sensor_data[]={53.2,52.6,52.7,53.2,52.8,53.3,49.7,53.1};
	CU_ASSERT( valid_fused_output(counter_outof_range,2, weight_coeff,sensor_data,8)>=-34.070078);
	CU_ASSERT( valid_fused_output(counter_outof_range,2, weight_coeff,sensor_data,8)>=-34.070078);
}



/**
	*********** Test Runner Code goes here *************
*/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /**
	* initialize the CUnit test registry 
	*/
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /**
   * add a suite to the registry 
   */
   pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /** 
   add the tests to the suite 
   */
   if ( (NULL == CU_add_test(pSuite, "weightcoefficient_test_1", weightcoefficient_test_1)) ||
        (NULL == CU_add_test(pSuite, "calc_threshold_test_1", calc_threshold_test_1)) ||
        (NULL == CU_add_test(pSuite, "read_file_test_1", read_file_test_1)) ||
        (NULL == CU_add_test(pSuite, "detect_out_of_range_sensor_test_1", detect_out_of_range_sensor_test_1))|| 
        (NULL == CU_add_test(pSuite, "valid_fused_output_test_1", valid_fused_output_test_1))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /**
   * Run all tests using the basic interface 
   */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
   /** 
   * Clean up registry and return 
   */
   CU_cleanup_registry();
   return CU_get_error();
}
