/**
********************************************************************************
*
*	@file		test.cpp
*
*	@brief		This content holds the tests for the maniuplation of the 'Image' class by using a test image and testing the functions.
*
*	@version	1.0
*
*	@date		11/11/2015
*
*	@author		Michael P. J. Smith <eeu213>
*
*
********************************************************************************
*/


//******************************************************************************
//	Include
//******************************************************************************
#include <sstream>
#include <exception>
#include <iostream>

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
        // Good number of arguments
        if (argc == 2)
        {
            // Load an image

			// Task 1 default constructor
            Image task1_image;
			task1_image.loadPGM(argv[1]); // loads an image from an inputted arguement


			// Task 2 copy constructor copies data from one image reference to the next
			// used in most methods

			// Task 3 destructor (destroys the image)
			// used in most methods

			// Task 4 copy operator
			Image task4_image = task1_image; // copies data from task1_image to task_4 image
			task4_image.savePGM("task4.pgm"); // saves task4_image and outputs a *.pgm file

			// Task 5 addition operator
			Image task5_image = task1_image + task4_image; // adds the data in task 1 and the data in task 4 and stores it in task 5
			task5_image.savePGM("task5.pgm"); 
			//task5_image.destroy(); // releases the memory

			// Task 6 subtraction operator
			Image task6_image = task1_image - task4_image / 2; // subtracts the data in task 1 from the data in task 4 divided by 2 and stores it in task 6
			task6_image.savePGM("task6.pgm");
			task6_image.destroy();

			// Task 7 addition assignment
			Image task7_image = task1_image; // copies elements from task 1 to task 7
			task7_image += task4_image; // adds elements from task 4 onto the elements already existing in task 7
			task7_image.savePGM("task7.pgm");
			task7_image.destroy();

			// Task 8 subtraction assignment
			Image task8_image = task1_image;
			task8_image -= task4_image/2; // subtracts elements already existing in task 8 by the elements in task 4
			task8_image.savePGM("task8.pgm");
			task8_image.destroy();

			// Task 9 operator add aValue to every pixel
			Image task9_image;
			task9_image = task1_image + 130; // adds 130 to every value in task 1 and stores the result in task 9
			task9_image.savePGM("task9.pgm");
			task9_image.destroy();

			// Task 10 operator subtract aValue from every pixel
			Image task10_image;
			task10_image = task1_image - 50; // subtracts 50 from every value in task 1 and stores the result in task 10
			task10_image.savePGM("task10.pgm");
			task10_image.destroy();

			// Task 11 operator multiply every pixel by aValue
			Image task11_image;
			task11_image = task1_image * 2; // multiplies every value in task 1 by 2 and stores the result in task 11
			task11_image.savePGM("task11.pgm");
			task11_image.destroy();

			// Task 12 operator divide every pixel by aValue
			Image task12_image = task1_image;
			task12_image = task12_image / 2; // divides every value in task 1 by 2 and stores the results in task 12
			task12_image.savePGM("task12.pgm");
			task12_image.destroy();

			// Task 13 assignment add aValue to every pixel
			Image task13_image = task1_image;
			task13_image += 70; // adds 70 to every value already stored in task 13
			task13_image.savePGM("task13.pgm");
			task13_image.destroy();

			// Task 14 assignment subtract a aValue from every pixel
			Image task14_image = task1_image;
			task14_image -= 25; // subtracts 25 from every value already stored in task 14
			task14_image.savePGM("task14.pgm");
			task14_image.destroy();

			// Task 15 assignment multiple every pixel by aValue
			Image task15_image = task1_image;
			task15_image *= 1.5; // multiplies every value already stored in task 15 by 1.5
			task15_image.savePGM("task15.pgm");
			task15_image.destroy();

			// Task 16 assignment divide every pixel by aValue
			Image task16_image = task1_image;
			task16_image /= 1.5; // divides every value already stored in task 16 by 1.5
			task16_image.savePGM("task16.pgm");
			task16_image.destroy();

			// Task 17 negation operator
			Image task17_image;
			task17_image = !task1_image; // makes every pixel in task 1 equal 255 - pixelValue (inverse the pixel values) and save it in task 17
			task17_image.savePGM("task17.pgm");
			task17_image.destroy();

			// Task 18 width accessor
			unsigned int task18_image_width = task1_image.getWidth(); // accesses and returns the width of task 1 
			std::cout << "Image width = " << task18_image_width << std::endl; // prints out the width
			 
			// Task 19 height accessor
			unsigned int task19_image_height = task1_image.getHeight(); // accesses and returns the height of task 1
			std::cout << "Image height = " << task19_image_height << std::endl; // prints out the height

			// Task 20 aspect ratio
			float task20_image_aspect_ratio = task1_image.getAspectRatio(); // accesses and returns the aspect ratio of task 1
			std::cout << "Aspect ratio = " << task20_image_aspect_ratio << ":1" << std::endl; // prints out the aspect ratio

			// Task 21 set aValue to a pixel
			task1_image.setPixel(3, 3, 0); // sets the pixel in task 1 on row 3 column 3 to equal 0
			task1_image.savePGM("task21.pgm"); 

			// Task 22 return aValue
			task1_image.loadPGM(argv[1]);
			unsigned char task22_image_pixel = task1_image.getPixel(5, 5); // accesses and returns the pixel value in task 1 at row 5 column 5
			std::cout << "Pixel at row 5 column 5 = " << (int)task22_image_pixel << std::endl; // prints out that pixel value

			// Task 23 read from RAW
			Image task23_image;
			task23_image.loadRAW("snow.raw"); // loads an image from *.raw
			task23_image.savePGM("task23.pgm"); // saves as *.pgm 
			task23_image.destroy();

			// Task 24 write to RAW
			task1_image.saveRAW("task24.raw"); // saves a *.pgm as *.raw

			// Task 25 return smallest value
			float task25_image_min_value = task1_image.getMinValue(); // accesses and returns the smallest value from task 1
			std::cout << "Minumum value = " << task25_image_min_value << std::endl; // prints out the smallest value

			// Task 26 return largest value
			float task26_image_max_value = task1_image.getMaxValue(); // accesses and returns the largest value from task 1
			std::cout << "Maximum value = " << task26_image_max_value << std::endl; // prints out the largest value

			// Task 27 normalise image
			task1_image.loadPGM(argv[1]);
			Image task27_image = task1_image;
			task27_image.normaliseImage(); // normalises all the values in the image between 0 and 255
			task27_image.savePGM("task27.pgm");
			task27_image.destroy();

			// Task 28 ROI
			Image task28_image = task1_image; 
			task28_image = task28_image.getROI(1350, 2000, 50, 400); // gets the region of interest cropping to anything within xStart xEnd (per element) :: yStart yEnd (per line)
			task28_image.savePGM("task28.pgm");
			task28_image.destroy();
	
        }


        // Wrong number of argument
        else
        {
            // Build the error message
            std::stringstream error_message;
            error_message << "Wrong number of arguments, usage:" << std::endl;
            error_message << "\t" << argv[0] << " input_file_name.pgm " << std::endl;
        
            // Throw the error
            throw (error_message.str());
        }
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

	system("PAUSE");
    return (error_code);
}
