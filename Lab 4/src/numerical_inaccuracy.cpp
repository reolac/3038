/**
********************************************************************************
*
*	@file		numerical_inaccuracy.cpp
*
*	@brief		File to experiment with numerical inaccuracy.
*
*	@version	1.0
*
*	@date		17/11/2015
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
#include<iomanip>
#include<cmath>

bool isEqual(float i, float j) {
	float difference = i - j;
	float epsilon = 0.00001;
	if (difference < epsilon)
		return (true);
	else
		return (false);
}

int main()
{
	float i = 10.11111;
	float j = 20.22222;
	float k = i + j;
	float l = j + i;
	float m = 30.33333;

	std::cout << k << "\t" << l << "\t" << m << std::endl;

	std::cout << (k == l ? "SAME" : "DIFFERENT") << std::endl; 
	std::cout << (m == k ? "SAME" : "DIFFERENT") << std::endl; 
	std::cout << (m == l ? "SAME" : "DIFFERENT") << std::endl;

	std::cout << std::setprecision(17) << k << "\t" << 
		std::setprecision(17) << l << "\t" << std::setprecision(17) << m << std::endl;

	std::cout << (isEqual(k, l) ? "SAME" : "DIFFERENT") << std::endl; 
	std::cout << (isEqual(m, k) ? "SAME" : "DIFFERENT") << std::endl; 
	std::cout << (isEqual(m, l) ? "SAME" : "DIFFERENT") << std::endl;

	system("Pause");

    return 0;
}
