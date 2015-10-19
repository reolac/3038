/**
********************************************************************************
*
*	@file		task2.cpp
*
*	@brief		Here explain here what is the file about.
*
*	@version	1.0
*
*	@date		06/10/2015
*
*	@author		eeu213
*
*
********************************************************************************
*/


//******************************************************************************
//	Include
//******************************************************************************
#include<iostream>


//******************************************************************************
//	namespace
//******************************************************************************
using namespace std;


//******************************************************************************
//	Global variables
//******************************************************************************


//******************************************************************************
//	Function declaration
//******************************************************************************


//******************************************************************************
//	Implementation
//******************************************************************************
int main(int argc, char** argv)
{
	float sum = 0.0;
	if (argc % 2 != 0 && argc != 1) {
		for (int i = 1; i < argc; i++) {
			sum = sum + atof(argv[i]);
		}
		cout << sum;
	}
	else {
		cerr << "Number of arguments are incorrect, please enter an even amount. Program exiting.";
		return (1);
	}

    // Exit code
    return (0);
}