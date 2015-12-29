/**
********************************************************************************
*
*	@file		test.cpp
*
*	@brief		BRIEF DESCRIPTION ABOUT THE CONTENT OF THE FILE.
*
*	@version	1.0
*
*	@date		DATE HERE
*
*	@author		YOUR NAME HERE
*
*
********************************************************************************
*/


//******************************************************************************
//	Include
//******************************************************************************
#include <sstream>
#include <iostream>
#include <exception>
#include <vector>
#include "Image.h"


//-----------------------------
int main(int argc, char** argv)
//-----------------------------

{
	// Return code
	int error_code(0);

	// Catch exceptions
	try
	{
		// Load an image
		Image input_1;
		input_1.loadPGM("input1.pgm");

		/*
		// Task 1a: NCC on the same image
		Image task_1a = input_1;
		std::cout << "NCC of the same image = " << (int)task_1a.getNCC(input_1) << std::endl;

		// Task 1b: NCC on the inverse of the image
		Image task_1b = !input_1;
		std::cout << "NCC of an inverted image = " << (int)task_1b.getNCC(input_1) << std::endl;
		
		
		// Task 2: SAE
		Image task_2a = input_1;
		std::cout << "SAE of the same image = " << task_2a.getSAE(input_1) << std::endl;

		Image task_2b = !input_1;
		std::cout << "SAE of an inverted image= " << task_2b.getSAE(input_1) << std::endl;
		
		




		// Task 3: Histogram
		Image task_3a = input_1;
		task_3a.getHistogram(10, "task3a.dat");
		std::cout << "Histogram 1 saved at \"/task3a.dat\"." << std::endl;

		task_3a.getHistogram(5, "task3b.dat");
		std::cout << "Histogram 2 saved at \"/task3b.dat\"." << std::endl;

		Image task_3c = input_1 + 100;
		task_3c.getHistogram(10, "task3c.dat");
		std::cout << "Histogram 3 saved at \"/task3c.dat\"." << std::endl;
		

		
		//Task 4: Thresholding
		Image task_4 = input_1 <= 120;
		task_4.savePGM("task4.pgm");
		std::cout << "Threshold result saved at \"task4.pgm\"." << std::endl;
		
		
		// Task 5: Blending
		Image task_5 = input_1 * 2;
		task_5 = task_5.blendImage(input_1, 0.33);
		task_5.savePGM("task5.png");
		std::cout << "Blending result saved at \"task5.pgm\"." << std::endl;
		
		
		// Task 6: Resize
		Image task_6a;
		task_6a = input_1.resizeImage(2);
		task_6a.savePGM("task6a.pgm");

		Image task_6b;
		task_6b = input_1	.resizeImage(3);
		task_6b.savePGM("task6b.pgm");
		



		
		

		
		// Task 7: Median Filter
		Image task_7 = input_1;
		task_7 = task_7.useMedianFilter();
		task_7.savePGM("task7.pgm");
		*/
		
		// Task 8: Spacial Convolution
		Image task_8 = input_1;
		std::vector<int> task_8_filter = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };
		task_8 = task_8.useSpacialConvolution(task_8_filter);
		task_8.savePGM("task8.pgm");
		
		//Task 9a: Edge detection
		Image task_9_a = input_1;
		task_9_a = task_9_a.detectEdges();
		task_9_a.savePGM("task9a.pgm");

		//Task 9b: Sharpen
		Image task_9_b = input_1;
		task_9_b = task_9_b.sharpenImage();
		task_9_b.savePGM("task9b.pgm");
		
		//Task 9c: Box blur
		Image task_9_c = input_1;
		task_9_c = task_9_c.useBoxBlurFilter();
		task_9_c.savePGM("task9c.pgm");

		// Task 9d: Gaussian Blur
		Image task_9_d = input_1;
		task_9_d = task_9_d.useGaussianFilter();
		task_9_d.savePGM("task9d.pgm");
		/**/



	}
	// An error occured
	catch (const std::exception& error)
	{
		error_code = 1;
		std::cerr << error.what() << std::endl;
	}
	catch (const std::string& error)
	{
		error_code = 1;
		std::cerr << error << std::endl;
	}
	catch (const char* error)
	{

		error_code = 1;
		std::cerr << error << std::endl;
	}
	catch (...)
	{
		error_code = 1;
		std::cerr << "Unknown error" << std::endl;
	}

	system("pause");
	return (error_code);
}
