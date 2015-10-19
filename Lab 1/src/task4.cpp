/**
********************************************************************************
*
*	@file		task1.cpp
*
*	@brief		Here explain here what is the file about.
*
*	@version	1.0
*
*	@date		06/10/2015
*
*	@author		Your name
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
int main()
{
	int no_Numbers;

	cout << "Enter amount of numbers to sum : ";
	cin >> no_Numbers;

	float* numbers = new float[no_Numbers];
	
	cout << "Enter numbers to sum : ";

	for (int i = 0; i <= no_Numbers ; i++)
	{
		cin >> *numbers;

		*numbers++;
	}


	*numbers--;

	float current;
	float next;
	float temp;
	cout << "Printing out stored numbers \n";
	for (int i = 0; i <= no_Numbers; i++)
	{	
		current = *numbers;
		*numbers--;
		next = *numbers;
		
		
		if (next > current)
		{
			*numbers++;
			*numbers = next;
			*numbers--;
			*numbers = current;
		}

		cout << *numbers;
		cout << "\n";
	}

	delete[] numbers;

    // Exit code
    return (0);
}
