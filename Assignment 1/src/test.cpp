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
        if (argc == 3)
        {
            // Load an image
            Image test_image;
            test_image.loadPGM(argv[1]);
        
            // Save the image
            test_image.savePGM(argv[2]);
        
        
            // WRITE YOUR CODE HERE TO TEST THE CLASS
        }
        // Wrong number of argument
        else
        {
            // Build the error message
            std::stringstream error_message;
            error_message << "Wrong number of arguments, usage:" << std::endl;
            error_message << "\t" << argv[0] << " input_file_name.pgm output_file_name.pgm" << std::endl;
        
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

    return (error_code);
}
