#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/file_operations.h"
int main(int argc, char ** argv){						
    if (argc < 2) {
       printf("Wrong parameters entered. The program must be invoked as follow:");
        return 1; 
    }  
    char * i_input =  argv[1];						/*initialize filename with parameters passed into main*/
	read_from_file(i_input);
	return 0;
}
