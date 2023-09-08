#include "types.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Safely print first argument provided to the program. Determine its meaning.
 * 
 * @param argc total number of arguments provided to the program
 * 
 * @param argv array/vector of arguments
*/
void print_first_argument(int argc, char *argv[]) {

  return;
}

/**
 * Safely print first 4 arguments provided to the program while converting them to their corresponding data type.
 * 
 * ./main <int> <double> <string>
 * 
 * To convert <string> to <int>, use function atoi() (https://cplusplus.com/reference/cstdlib/atoi/)
 * 
 * To convert <string> to <double>, use function atof() (https://cplusplus.com/reference/cstdlib/atof/)
 * 
 * Use the following commmand to execute your program with set of arguments: 
 * 
 *      ./main 42 13.37 hello_program 
 * 
 * @param argc total number of arguments provided to the program
 * 
 * @param argv array/vector of arguments
*/
void print_parse_arguments(int argc, char *argv[]) {

	return;
}

/**
 * Safely print ALL arguments provided to the program without any conversion.
 * 
 * ./main <int> <double> <string>
 * 
 * @param argc total number of arguments provided to the program
 * 
 * @param argv array/vector of arguments
*/
void print_all_arguments(int argc, char *argv[]) {
  
  return;
}


#ifndef TEST_BUILD

int main(int argc, char *argv[]) {

  //TODO: 1. Call functions and pass argc and argv
  return 0;
}

#endif
