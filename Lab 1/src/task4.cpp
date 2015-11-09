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
float* numbers;
int no_Numbers;

//******************************************************************************
//	Function declaration
//******************************************************************************


//******************************************************************************
//	Implementation
//******************************************************************************
void swap(int i)
{
	float temp = numbers[i];
	numbers[i] = numbers[i + 1];
	numbers[i + 1] = temp;
	cout << "running swap";
}

void sort()
{
	float current;
	float next;
	cout << "running sort";
	for (int i = 0; i < no_Numbers; i++)
	{
		current = numbers[i];
		next = numbers[i + 1];

		if (next > current)
		{
			swap(i);
			
		}
		cout << numbers[i];
		cout << "\n";
	}
}



int main()
{

	cout << "Enter amount of numbers to sum : ";
	cin >> no_Numbers;

	numbers = new float[no_Numbers];
	
	cout << "Enter numbers to sum : ";

	for (int i = 0; i < no_Numbers ; i++)
	{
		cin >> numbers[i];
	}

	sort();

	cout << "Printing out stored numbers \n";
	for (int i = 0; i < no_Numbers; i++)
	{	
		cout << numbers[i];
		cout << "\n";
	}

	delete[] numbers;

    // Exit code
    return (0);
}

