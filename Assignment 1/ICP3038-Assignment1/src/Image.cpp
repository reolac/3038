/**
********************************************************************************
*
*	@file		Image.cpp
*
*	@brief		This file holds the logic for all of the functions and the overloads for the Image class. Requires a tester to test.
*
*	@version	1.0
*
*	@date		27/10/2015
*
*	@author		Michael P. J. Smith <eeu213>
*
*
********************************************************************************
*/


//******************************************************************************
//	Define
//******************************************************************************
#define LINE_SIZE 2048


//******************************************************************************
//	Include
//******************************************************************************
#include <sstream> // Head file for stringstream
#include <fstream> // Head file for filestream
#include <algorithm>
#include <iostream>

#include "Image.h" // the image class declaration file



//------------------
Image::Image() : // constructor
	//------------------
	m_width(0), // sets all elements of the Image class to 0
	m_height(0),
	m_p_image(0)
	//------------------
{
}


//--------------------------------
Image::Image(const Image& anImage) : // constructor with initalization
	//--------------------------------
	m_width(anImage.m_width), // copies the width of anImage to this image
	m_height(anImage.m_height), // copies the height of anImage to this image
	m_p_image(anImage.m_p_image) // copies the data pointer of anImage to this image
	//------------------
{
	m_p_image = new float[anImage.m_width * anImage.m_height]; // initalize a new array to store data for this image
	// m_width * m_height is the total amount of pixels (resolution) thus the required size of the array
	for (unsigned int i(0); i < m_width * m_height; i++) 
	{
		m_p_image[i] = anImage.m_p_image[i]; // copy array data from anImage to this 
	}	
}


//-------------
Image::~Image() // destructor
//-------------
{
	if (m_p_image) delete[] m_p_image; // if m_p_image has been allocated, delete it
}


//-------------------
void Image::destroy() 
//-------------------
{
	// Memory has been dynamically allocated
	if (m_p_image)
	{
		// Release the memory
		delete[] m_p_image;

		// Make sure the pointer is reset to NULL
		m_p_image = 0;
	}

	// There is no pixel in the image
	m_width = 0;
	m_height = 0;
}


//-------------------------------------------
Image& Image::operator=(const Image& anImage) // image1 = image2
//-------------------------------------------
{
	if (m_p_image) delete[] m_p_image; // if m_p_image has been allocated, delete it

	m_width = anImage.m_width; // copies the width of anImage to this image
	m_height = anImage.m_height; // copies the height of anImage to this image
	m_p_image = new float[anImage.m_width * anImage.m_height]; // creates a new array to store the image data in

	for (unsigned int i(0); i < m_width * m_height; i++) // m_width * m_height = resolution = total required elements for this picture
	{
		m_p_image[i] = anImage.m_p_image[i]; // copies data from anImage to this image, element by element
	}
	
	return (*this); // returns a reference to this image
}


//------------------------------------------
Image Image::operator+(const Image& anImage) // image1 = image2 + image 3
//------------------------------------------
{
	Image new_image; // create a new image to return

	new_image.m_height = std::min(anImage.m_height, m_height); // get the min height out of the two images and store it as the height
	new_image.m_width = std::min(anImage.m_width, m_width); // get the min width out of the two images and store it as the width
	// this ensures that if images are of different sizes all of the points can still be allocated against each other 

	new_image.m_p_image = new float[new_image.m_width * new_image.m_height]; // creates a new aray to store the image data

	for (unsigned int i(0); i < new_image.m_width * new_image.m_height; i++) // new_image.m_width * new_image.m_height = resolution = total required elements for this picture
	{
		new_image.m_p_image[i] = m_p_image[i] + anImage.m_p_image[i]; // adds data from one image to the data from the other image and stores it in the new image, element by element
	}

	return (new_image); // returns this new image
}


//------------------------------------------
Image Image::operator-(const Image& anImage) // image1 = image2 - image3
//------------------------------------------
{
	Image new_image; 

	new_image.m_height = std::min(anImage.m_height, m_height); 
	new_image.m_width = std::min(anImage.m_width, m_width); 


	new_image.m_p_image = new float[new_image.m_width * new_image.m_height]; 

	for (unsigned int i(0); i < new_image.m_width * new_image.m_height; i++)
	{
		new_image.m_p_image[i] = m_p_image[i] - anImage.m_p_image[i]; // subracts data from one image from the data of the other image and stores it in the new image, element by element
	}

	return (new_image);
}


//--------------------------------------------
Image& Image::operator+=(const Image& anImage) // image1 += image2
//--------------------------------------------
{
	m_height = std::min(anImage.m_height, m_height); // gets the min height from this image and the other image
	m_width = std::min(anImage.m_width, m_width); // gets the min width from this image and the other image

	for (unsigned int i(0); i < m_height * m_width; i++)
	{
		m_p_image[i] += anImage.m_p_image[i]; // adds values from the other image onto the existing values in this image, element by element
	}

	return (*this); // return a reference to this image
}


//--------------------------------------------
Image& Image::operator-=(const Image& anImage) // image1 -= image2
//--------------------------------------------
{
	m_height = std::min(anImage.m_height, m_height);
	m_width = std::min(anImage.m_width, m_width);


	for (unsigned int i(0); i < m_height * m_height; i++)
	{
		m_p_image[i] -= anImage.m_p_image[i]; // subtracts the existing values in this image by the values in the other image, element by element
	}

	return (*this);
}


//----------------------------------
Image Image::operator+(float aValue) // image1[19] = 50; image1[20] = 100; image2 = image1 + 4; image2[19] = 54; image2[20] = 104; 
//----------------------------------
{
	Image new_image;

	new_image.m_height = m_height; // copies height of current image to new image 
	new_image.m_width = m_width; // copies width of current image to new image

	new_image.m_p_image = new float[new_image.m_width * new_image.m_height];

	for (unsigned int i(0); i < new_image.m_width * new_image.m_height; i++)
	{
		new_image.m_p_image[i] = m_p_image[i] + aValue; // adds a set value onto every element of the original image, element by element, then stores it in a new image
	}

	return (new_image); // returns this new image

}


//----------------------------------
Image Image::operator-(float aValue) // image1[19] = 50; image1[20] = 100; image2 = image1 - 4; image2[19] = 46; image2[20] = 96;
//----------------------------------
{
	Image new_image;

	new_image.m_height = m_height;
	new_image.m_width = m_width;

	new_image.m_p_image = new float[new_image.m_width * new_image.m_height];

	for (unsigned int i(0); i < new_image.m_width * new_image.m_height; i++)
	{
		new_image.m_p_image[i] = m_p_image[i] - aValue; // subtracts every element of the original image by a set value, element by element, then stores it in a new image
	}

	return (new_image);
}


//----------------------------------
Image Image::operator*(float aValue) // image1[19] = 50; image1[20] = 100; image2 = image1 * 2; image2[19] = 100; image2[20] = 200;
//----------------------------------
{
	Image new_image;

	new_image.m_height = m_height;
	new_image.m_width = m_width;

	new_image.m_p_image = new float[new_image.m_width * new_image.m_height];

	for (unsigned int i(0); i < new_image.m_width * new_image.m_height; i++)
	{
		new_image.m_p_image[i] = m_p_image[i] * aValue; // multiplies every element of the original image by a set value, element by element, then stores it in a new image
	}

	return (new_image);
}


//----------------------------------
Image Image::operator/(float aValue) // image1[19] = 50; image1[20] = 100; image2 = image1 / 2; image2[19] = 25; image2[20] = 50;
//----------------------------------
{
	Image new_image;

	new_image.m_height = m_height;
	new_image.m_width = m_width;

	new_image.m_p_image = new float[new_image.m_width * new_image.m_height];

	for (unsigned int i(0); i < new_image.m_width * new_image.m_height; i++)
	{
		new_image.m_p_image[i] = m_p_image[i] / aValue; // divides every element of the original image by a set value, element by element, then stores it in a new image
	}

	return (new_image);
}


//-----------------------------------
Image& Image::operator+=(float aValue) // image[19] = 50; image[20] = 100; image + 4; image[19] = 54; image[20] = 104;
//-----------------------------------
{
	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] += aValue; // adds a value onto every value of this image, element by element
	}

	return (*this); // returns a reference to this image
}


//------------------------------------
Image& Image::operator-=(float aValue) // image[19] = 50; image[20] = 100; image - 4; image[19] = 46; image[20] = 96;
//------------------------------------
{
	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] -= aValue; // subtracts a value from every element in the image
	}

	return (*this);
}


//------------------------------------
Image& Image::operator*=(float aValue) // image[19] = 50; image[20] = 100; image * 2; image[19] = 100; image[20] = 200;
//------------------------------------
{
	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] *= aValue; // multiplies every element of the image by a value, element by element
	}

	return (*this);
}


//------------------------------------
Image& Image::operator/=(float aValue) // image[19] = 50; image[20] = 100; image / 2; image[19] = 25; image[20] = 50;
//------------------------------------
{
	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] /= aValue; // divides every element of the image by a value, element by element
	}

	return (*this);
}


//----------------------
Image Image::operator!() // image[0] = 255; image[1] = 138; image = !image; image[0] = 0; image[1] = 117;  #(255 - 0) (255 - 138)
//----------------------
{
	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] = 255 - m_p_image[i]; // sets every element to 255 and subtracts what the original value was (high values become low, low becomes high)
	}

	return (*this);
}


//------------------------------
float Image::getMaxValue() const // searches the data to find the max value
//------------------------------
{
	return (*std::max_element(&m_p_image[0], &m_p_image[m_width * m_height]));
}


//------------------------------
float Image::getMinValue() const // searches the data to find the min value
//------------------------------
{
	return (*std::min_element(&m_p_image[0], &m_p_image[m_width * m_height]));
}


//----------------------------------------------------------------
void Image::normaliseImage() const // evenly spread the data between 0 and 255 maximizing all data points
//----------------------------------------------------------------
{
	unsigned int maxValue = getMaxValue(); // gets and stores the highest pixel in the image
	unsigned int minValue = getMinValue(); // gets and stores the lowest pixel in the image

	for (unsigned int i(0); i < m_width * m_height; i++)
	{ // makes the min value zero (minus all elements by the min value); divide it by the difference between the maximum and minimum value 
		m_p_image[i] = 255 * ((m_p_image[i] - minValue) / (maxValue - minValue)); // multiply that by the highest possible number for the data (255)
	}
}


//------------------------------------------------------------------------------------------------------------
Image Image::getROI(unsigned int startingX, unsigned int endingX, unsigned int startingY, unsigned int endingY) 
//------------------------------------------------------------------------------------------------------------
{ // coordinates to create a rectangular/square bounding box and copy the data inside that box to a new array
	Image new_image;
	
	unsigned int width = endingX - startingX; // get the width of the new image by subtracting the ending column by the starting column
	unsigned int height = endingY - startingY; // get the height of the image by subtracting the ending row by the starting row
	
	new_image.m_width = width;
	new_image.m_height = height;	
	new_image.m_p_image = new float[new_image.m_width * new_image.m_height];
	
	for (unsigned int i(0); i < width; i++) // traverse the columns of the image
	{
		for (unsigned int j(0); j < height; j++) // traverse the rows of the image
		{  // get the data from the original data by using an offset on the coordinates
			new_image.m_p_image[j * width + i] = getPixel(i+startingX, j+startingY);
		}  // store the data in the new image
	}	

	return (new_image);
}


//----------------------------------------------------------------
void Image::shiftScaleFilter(float aShiftValue, float aScaleValue)
//----------------------------------------------------------------
{
	// Process every pixel of the image
	for (unsigned int i = 0; i < m_width * m_height; ++i)
	{
		// Apply the shilft/scale filter
		m_p_image[i] = (m_p_image[i] + aShiftValue) * aScaleValue;
	}
}


//----------------------------------------
void Image::loadPGM(const char* aFileName)
//----------------------------------------
{
	// Open the file
	std::ifstream input_file(aFileName);

	// The file does not exist
	if (!input_file.is_open())
	{
		// Build the error message
		std::stringstream error_message;
		error_message << "Cannot open the file \"" << aFileName << "\". It does not exist";

		// Throw an error
		throw (error_message.str());
	}
	// The file is open
	else
	{
		// Release the memory if necessary
		destroy();

		// Variable to store a line
		char p_line_data[LINE_SIZE];

		// Get the first line
		input_file.getline(p_line_data, LINE_SIZE);

		// Get the image type
		std::string image_type(p_line_data);

		// Invalid format
		if (image_type != "P2")
		{
			//Build the error message
			std::stringstream error_message;
			error_message << "Invalid file (\"" << aFileName << "\")";

			//Throw an error
			throw (error_message.str());
		}
		// Valid format
		else
		{
			// Variable to save the max value
			int max_value(-1);

			// There is data to read
			unsigned int pixel_count(0);
			while (input_file.good())
			{
				// Get the new line
				input_file.getline(p_line_data, LINE_SIZE);

				// It is not a comment
				if (p_line_data[0] != '#')
				{
					// Store the line in a stream
					std::stringstream stream_line;
					stream_line << std::string(p_line_data);

					// The memory is not allocated
					if (!m_p_image && !m_width && !m_height)
					{
						// Load the image size
						stream_line >> m_width >> m_height;

						// Alocate the memory
						m_p_image = new float[m_width * m_height];

						// Out of memory
						if (!m_p_image)
						{
							throw ("Out of memory");
						}
					}
					// The max value is not set
					else if (max_value < 0)
					{
						// Get the max value;
						stream_line >> max_value;
					}
					// Read the pixel data
					else
					{
						// Process all the pixels of the line
						while (stream_line.good())
						{
							// Get the pixel value
							int pixel_value(-1);
							stream_line >> pixel_value;
							// The pixel exists
							if (pixel_count < m_width * m_height)
							{
								m_p_image[pixel_count++] = pixel_value;
							}
						}
					}
				}
			}
		}
	}
}


//-----------------------------------------------
void Image::loadPGM(const std::string& aFileName)
//-----------------------------------------------
{
	loadPGM(aFileName.data());
}


//----------------------------------------
void Image::savePGM(const char* aFileName)
//----------------------------------------
{
	// Open the file
	std::ofstream output_file(aFileName);

	// The file does not exist
	if (!output_file.is_open())
	{
		// Build the error message
		std::stringstream error_message;
		error_message << "Cannot create the file \"" << aFileName << "\"";

		// Throw an error
		throw (error_message.str());
	}
	// The file is open
	else
	{
		// Set the image type
		output_file << "P2" << std::endl;

		// Print a comment
		output_file << "# ICP3038 -- Assignment 1 -- 2015/2016" << std::endl;

		// The image size
		output_file << m_width << " " << m_height << std::endl;

		// The get the max value
		output_file << std::min(255, std::max(0, int(getMaxValue()))) << std::endl;

		// Process every line
		for (unsigned int j = 0; j < m_height; ++j)
		{
			// Process every column
			for (unsigned int i = 0; i < m_width; ++i)
			{
				// Process the pixel
				int pixel_value(m_p_image[j * m_width + i]);
				pixel_value = std::max(0, pixel_value);
				pixel_value = std::min(255, pixel_value);

				output_file << pixel_value;

				// It is not the last pixel of the line
				if (i < (m_width - 1))
				{
					output_file << " ";
				}
			}

			// It is not the last line of the image
			if (j < (m_height - 1))
			{
				output_file << std::endl;
			}
		}
	}
}


//-----------------------------------------------
void Image::savePGM(const std::string& aFileName)
//-----------------------------------------------
{
	savePGM(aFileName.data());
}


//-----------------------------------------------
unsigned int Image::getWidth() // accesses the width of the image
//-----------------------------------------------
{
	return m_width; // returns the width of the image
}


//-----------------------------------------------
unsigned int Image::getHeight() // accesses the height of the image
//-----------------------------------------------
{
	return m_height; // returns the height of the image
}


//-----------------------------------------------
float Image::getAspectRatio() const // ratio of the image
//-----------------------------------------------
{ // divides the width by the height then round the result to 1 D.P
	return floor(((float(m_width) / float(m_height))*10) + 0.5)/10; 
}


//-----------------------------------------------
unsigned char Image::getPixel(unsigned int i, unsigned int j) const // gets the pixel knowing it's coordinates
//-----------------------------------------------
{	
	//std::cout << "Pixel at row 5 column 5 = " << m_p_image[j * m_width + i] << std::endl;
	return (m_p_image[j * m_width + i]); // returns the value by traversing through the 1D arraw
}


//-----------------------------------------------
void Image::setPixel(unsigned int i, unsigned int j, unsigned char aValue) // sets the pixel to a value
//-----------------------------------------------
{
	m_p_image[j * m_width + i] = aValue; // traverses through the 1D array, changes that value to the new value
}


//-----------------------------------------------
void Image::loadRAW(const std::string& aFileName) // loads and reads a file into image data
//-----------------------------------------------
{
	// Open the file
	std::ifstream input_file(aFileName);

	if (!input_file.is_open()) // if the file cannot be opened
	{
		// Build the error message
		std::stringstream error_message;
		error_message << "Cannot open the file \"" << aFileName << "\". It does not exist";

		// Throw an error
		throw (error_message.str());
	}

	else // if the file can be opened
	{		 
		std::string line; // to store a line
		float word; // to store each element of the line 

		int numberOfLines = 0; // counts the number of lines
		int numberOfWords = 0; // counts the number of elements 
		while (getline(input_file, line)) // whilst you can get a line, get a line
		{
			numberOfLines++; // increment the line count by 1
		}

		input_file.clear(); // clears the state of the file from eof to good
		input_file.seekg(0, std::ios::beg); // points at the start of the file

		while (!input_file.eof()) // while not the end of the file
		{ // whilst there are still words to process
			input_file >> word; // process the word (numbers no surrounded by white space)
			numberOfWords++; // add 1 to the word counter
		}

		input_file.clear(); // clears the state of the file from eof to good
		input_file.seekg(0, std::ios::beg); // points at the start of the file

		m_width = numberOfWords / numberOfLines; // divides the amount of words by the amount of lines
											   // to get the total width of the file

		m_height = numberOfLines; // stores the number of lines as the height of the file

		m_p_image = new float[m_width * m_height]; // allocates memory to store data

		for (int i = 0; i < m_width * m_height; i++)
		{
			input_file >> m_p_image[i]; // stores data from file into the array, element by element
		}

		input_file.close(); // close the file
	}
}


//-----------------------------------------------
void Image::saveRAW(const std::string & aFileName) // saves data from an image class into a file
//-----------------------------------------------
{
	std::ofstream output_file(aFileName);

	// The file does not exist
	if (!output_file.is_open())
	{
		// Build the error message
		std::stringstream error_message;
		error_message << "Cannot create the file \"" << aFileName << "\"";

		// Throw an error
		throw (error_message.str());
	}

	else 
	{
		for (unsigned int j = 0; j < m_height; ++j)
		{
			// Process every column
			for (unsigned int i = 0; i < m_width; ++i)
			{
				// Process the pixel
				int pixel_value(m_p_image[j * m_width + i]);
				pixel_value = std::max(0, pixel_value);
				pixel_value = std::min(255, pixel_value);

				output_file << pixel_value;

				// It is not the last pixel of the line
				if (i < (m_width - 1))
				{
					output_file << " ";
				}
			}

			// It is not the last line of the image
			if (j < (m_height - 1))
			{
				output_file << std::endl;
			}
		}
	}

}
