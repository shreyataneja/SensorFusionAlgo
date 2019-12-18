#include <CUnit/Basic.h>
#include "../include/file_operations.h"

void read_from_file_test(){
	try
	{
		read_from_file("../inputs_and_results/test__1.csv");
		return;
	}
	catch(Exception e)
	{
		Assert.Fail(ex.Message);
	}
}
