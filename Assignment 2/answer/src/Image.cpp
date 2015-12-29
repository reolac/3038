/**
********************************************************************************
*
*   @file       Image.cpp
*
*   @brief      Class to handle a greyscale image.
*
*   @version    1.0
*
*   @todo       Write here anything you did not implement.
*
*   @date       11/11/2016
*
*   @author     Franck Vidal
*
*
********************************************************************************
*/


//******************************************************************************
//  Define
//******************************************************************************
#define LINE_SIZE 2048


//******************************************************************************
//  Include
//******************************************************************************
#include <sstream> // Header file for stringstream
#include <fstream> // Header file for filestream
#include <algorithm> // Header file for min/max/fill
#include <cmath> // Header file for abs
#include <vector>
#include <iostream>

#include "Image.h"


//------------------
Image::Image() :
	//------------------
	m_width(0),
	m_height(0),
	m_p_image(0)
	//------------------
{}


//----------------------------------------------
Image::Image(const Image& anImage) :
	//----------------------------------------------
	m_width(anImage.m_width),
	m_height(anImage.m_height),
	m_p_image(new float[m_width * m_height])
	//----------------------------------------------
{
	// Out of memeory
	if (m_width && m_height && !m_p_image)
	{
		throw "Out of memory";
	}

	// Copy the data
	std::copy(anImage.m_p_image, anImage.m_p_image + m_width * m_height, m_p_image);
}


//----------------------------------------------
Image::Image(const float* apData,
	unsigned int aWidth,
	unsigned int aHeight) :
	//----------------------------------------------
	m_width(aWidth),
	m_height(aHeight),
	m_p_image(new float[m_width * m_height])
	//----------------------------------------------
{
	// Out of memeory
	if (m_width && m_height && !m_p_image)
	{
		throw "Out of memory";
	}

	// Copy the data
	std::copy(apData, apData + m_width * m_height, m_p_image);
}


//----------------------------------------------
Image::Image(unsigned int aWidth,
	unsigned int aHeight) :
	//----------------------------------------------
	m_width(aWidth),
	m_height(aHeight),
	m_p_image(new float[m_width * m_height])
	//----------------------------------------------
{
	// Out of memeory
	if (m_width && m_height && !m_p_image)
	{
		throw "Out of memory";
	}

	// Initialise the data
	std::fill_n(m_p_image, m_width * m_height, 0);
}


//-------------
Image::~Image()
//-------------
{
	// Release memory
	destroy();
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


//---------------------------------------------
Image Image::getROI(unsigned int i,
	unsigned int j,
	unsigned int aWidth,
	unsigned int aHeight) const
	//---------------------------------------------
{
	// Create a black image
	Image roi(aWidth, aHeight);

	// Process every row of the ROI
	for (unsigned y(0); y < aHeight; ++y)
	{
		// Process every column of the ROI
		for (unsigned x(0); x < aWidth; ++x)
		{
			unsigned int index_i(x + i);
			unsigned int index_j(y + j);

			// The pixel index is valid
			if ((index_i < m_width) && (index_j < m_height))
			{
				// Get the pixel intensity from the current instance
				float intensity(getPixel(index_i, index_j));

				// Set the pixel of the ROI
				roi.setPixel(x, y, intensity);
			}
		}
	}

	return (roi);
}


//----------------------------------------------------------------
void Image::setPixel(unsigned int i, unsigned int j, float aValue)
//----------------------------------------------------------------
{
	// The pixel index is not valid
	if (i >= m_width || j >= m_height)
	{
		throw "Invalid pixel coordinate";
	}

	// Change the pixel value
	m_p_image[j * m_width + i] = aValue;
}


//---------------------------------------------------------
float Image::getPixel(unsigned int i, unsigned int j) const
//---------------------------------------------------------
{
	// The pixel index is valid
	if (i >= m_width || j >= m_height)
	{
		throw "Invalid pixel coordinate";
	}



	// Return the pixel value
	return (m_p_image[j * m_width + i]);
}


//-------------------------------------------
Image& Image::operator=(const Image& anImage)
//-------------------------------------------
{
	// Release memory
	destroy();

	// Copy the image properites
	m_width = anImage.m_width;
	m_height = anImage.m_height;
	m_p_image = new float[m_width * m_height];

	// Out of memeory
	if (m_width && m_height && !m_p_image)
	{
		throw "Out of memory";
	}

	// Copy the data
	std::copy(anImage.m_p_image, anImage.m_p_image + m_width * m_height, m_p_image);

	// Return the instance
	return (*this);
}


//------------------------------------------
Image Image::operator+(const Image& anImage)
//------------------------------------------
{
	// Deal with images of different sizes
	unsigned int min_width(std::min(m_width, anImage.m_width));
	unsigned int min_height(std::min(m_height, anImage.m_height));

	// Copy the instance into a temporary variable
	Image temp(getROI(0, 0, min_width, min_height));

	// Copy the data
	for (unsigned int j(0); j < min_height; ++j)
	{
		for (unsigned int i(0); i < min_width; ++i)
		{
			temp.m_p_image[j * temp.m_width + i] += anImage.m_p_image[j * anImage.m_width + i];
		}
	}

	// Return the result
	return (temp);
}


//------------------------------------------
Image Image::operator-(const Image& anImage)
//------------------------------------------
{
	// Deal with images of different sizes
	unsigned int min_width(std::min(m_width, anImage.m_width));
	unsigned int min_height(std::min(m_height, anImage.m_height));

	// Copy the instance into a temporary variable
	Image temp(getROI(0, 0, min_width, min_height));

	// Copy the data
	for (unsigned int j(0); j < min_height; ++j)
	{
		for (unsigned int i(0); i < min_width; ++i)
		{
			temp.m_p_image[j * temp.m_width + i] -= anImage.m_p_image[j * anImage.m_width + i];
		}
	}

	// Return the result
	return (temp);
}


//--------------------------------------------
Image& Image::operator+=(const Image& anImage)
//--------------------------------------------
{
	// Re-use operator+
	*this = *this + anImage;

	// Return the result
	return (*this);
}


//--------------------------------------------
Image& Image::operator-=(const Image& anImage)
//--------------------------------------------
{
	// Re-use operator-
	*this = *this - anImage;

	// Return the result
	return (*this);
}


//----------------------------------
Image Image::operator+(float aValue)
//----------------------------------
{
	// Copy the instance into a temporary variable
	Image temp(*this);

	float* p_temp(temp.m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ += aValue;
	}

	// Return the result
	return (temp);
}


//----------------------------------
Image Image::operator-(float aValue)
//----------------------------------
{
	// Copy the instance into a temporary variable
	Image temp(*this);

	float* p_temp(temp.m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ -= aValue;
	}

	// Return the result
	return (temp);
}


//----------------------------------
Image Image::operator*(float aValue)
//----------------------------------
{
	// Copy the instance into a temporary variable
	Image temp(*this);

	float* p_temp(temp.m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ *= aValue;
	}

	// Return the result
	return (temp);
}


//----------------------------------
Image Image::operator/(float aValue)
//----------------------------------
{
	// Copy the instance into a temporary variable
	Image temp(*this);

	float* p_temp(temp.m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ /= aValue;
	}

	// Return the result
	return (temp);
}


//-----------------------------------
Image& Image::operator+=(float aValue)
//-----------------------------------
{
	float* p_temp(m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ += aValue;
	}

	// Return the result
	return (*this);
}


//------------------------------------
Image& Image::operator-=(float aValue)
//------------------------------------
{
	float* p_temp(m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ -= aValue;
	}

	// Return the result
	return (*this);
}


//------------------------------------
Image& Image::operator*=(float aValue)
//------------------------------------
{
	float* p_temp(m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ *= aValue;
	}

	// Return the result
	return (*this);
}


//------------------------------------
Image& Image::operator/=(float aValue)
//------------------------------------
{
	float* p_temp(m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		*p_temp++ /= aValue;
	}

	// Return the result
	return (*this);
}


//----------------------
Image Image::operator!()
//----------------------
{
	// Copy the instance into a temporary variable
	Image temp(*this);

	float min_value(getMinValue());
	float max_value(getMaxValue());
	float range(max_value - min_value);

	float* p_temp(temp.m_p_image);

	// Process every pixel
	for (unsigned int i(0); i < m_width * m_height; ++i, ++p_temp)
	{
		// Take care to preserve the dynamic of the image
		*p_temp = min_value + range * (1.0 - (*p_temp - min_value) / range);
	}

	// Return the result
	return (temp);
}


//---------------------------------
float Image::getAspectRatio() const
//---------------------------------
{
	return (float(m_width) / float(m_height));
}


//----------------------------------
unsigned int Image::getWidth() const
//----------------------------------
{
	return (m_width);
}


//-----------------------------------
unsigned int Image::getHeight() const
//-----------------------------------
{
	return (m_height);
}


//------------------------------
float Image::getMinValue() const
//------------------------------
{
	// The image is empty
	if (!m_p_image)
	{
		throw "Empty image";
	}

	return (*std::min_element(&m_p_image[0], &m_p_image[m_width * m_height]));
}


//------------------------------
float Image::getMaxValue() const
//------------------------------
{
	// The image is empty
	if (!m_p_image)
	{
		throw "Empty image";
	}

	return (*std::max_element(&m_p_image[0], &m_p_image[m_width * m_height]));
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


//---------------------
void Image::normalise()
//---------------------
{
	shiftScaleFilter(-getMinValue(), 1.0 / (getMaxValue() - getMinValue()));
}


//----------------------------------------
void Image::loadPGM(const char* aFileName)
//----------------------------------------
{
	// Open the file
	std::ifstream input_file(aFileName, std::ifstream::binary);

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

		// Valid ASCII format
		if (image_type == "P2")
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
		// Valid binary format
		else if (image_type == "P5")
		{
			// Variable to save the max value
			int max_value(-1);

			// There is data to read
			unsigned int pixel_count(0);
			while (input_file.good())
			{
				// Process as an ASCII file
				if (!m_width || !m_height || max_value < 0)
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
						else
						{
							// Get the max value;
							stream_line >> max_value;
						}
					}
				}
				// Read the pixel data
				else
				{
					unsigned char* p_temp(new unsigned char[m_width * m_height]);

					// Out of memory
					if (!p_temp)
					{
						throw ("Out of memory");
					}

					input_file.read(reinterpret_cast<char*>(p_temp), m_width * m_height);

					for (unsigned int i(0); i < m_width * m_height; ++i)
					{
						m_p_image[i] = p_temp[i];
					}
					delete[] p_temp;
				}
			}
		}
		// Invalid format
		else
		{
			// Build the error message
			std::stringstream error_message;
			error_message << "Invalid file (\"" << aFileName << "\")";

			// Throw an error
			throw (error_message.str());
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


//----------------------------------------
void Image::loadRaw(const char* aFileName,
	unsigned int aWidth,
	unsigned int aHeight)
	//----------------------------------------
{
	// Open the file in binary
	std::ifstream input_file(aFileName, std::ifstream::binary);

	// The file is not open
	if (!input_file.is_open())
	{
		std::string error_message("The file (");
		error_message += aFileName;
		error_message += ") does not exist";

		throw error_message;
	}

	// Get size of file
	input_file.seekg(0, input_file.end);
	unsigned int size(input_file.tellg());

	// The size is not correct
	if (aWidth * aHeight * sizeof(float) != size)
	{
		std::stringstream error_message;
		error_message << "The size of " << aFileName << " is not " <<
			aWidth << "x" << aHeight;

		throw error_message.str();
	}

	// Rewind the file
	input_file.seekg(0);

	// Release the memory
	destroy();

	// Allocate memory for file content
	m_width = aWidth;
	m_height = aHeight;
	m_p_image = new float[m_width * m_height];

	// Read content of input_file
	input_file.read(reinterpret_cast<char*>(m_p_image), size);
}


//-----------------------------------------------
void Image::loadRaw(const std::string& aFileName,
	unsigned int aWidth,
	unsigned int aHeight)
	//-----------------------------------------------
{
	loadRaw(aFileName.data(), aWidth, aHeight);
}


//----------------------------------------
void Image::saveRaw(const char* aFileName)
//----------------------------------------
{
	// Open the file in binary
	std::ofstream output_file(aFileName, std::ifstream::binary);

	// The file is not open
	if (!output_file.is_open())
	{
		std::string error_message("The file (");
		error_message += aFileName;
		error_message += ") cannot be created";

		throw error_message;
	}

	// Write content to file
	output_file.write(reinterpret_cast<char*>(m_p_image), m_width * m_height * sizeof(float));
}


//-----------------------------------------------
void Image::saveRaw(const std::string& aFileName)
//-----------------------------------------------
{
	saveRaw(aFileName.data());
}


//------------------------------------------
void Image::loadASCII(const char* aFileName)
//------------------------------------------
{
	// Open the file
	std::ifstream input_file(aFileName);

	// The file is not open
	if (!input_file.is_open())
	{
		std::string error_message("The file (");
		error_message += aFileName;
		error_message += ") does not exist";

		throw error_message;
	}

	// Load the data into a vector
	std::vector<float> p_data;
	std::string line;
	int number_of_rows(0);
	int number_of_columns(0);

	// Read evely line
	while (std::getline(input_file, line))
	{
		number_of_columns = 0;
		float intensity;
		std::stringstream line_parser;
		line_parser << line;
		while (line_parser >> intensity)
		{
			p_data.push_back(intensity);
			++number_of_columns;
		}
		++number_of_rows;
	}

	// Wrong number of pixels
	if (number_of_rows * number_of_columns != p_data.size())
	{
		std::string error_message("The file (");
		error_message += aFileName;
		error_message += ") is invalid";

		throw error_message;
	}

	// Release the memory
	destroy();

	// Allocate memory for file content
	m_width = number_of_columns;
	m_height = number_of_rows;
	m_p_image = new float[m_width * m_height];

	// Copy the data
	std::copy(p_data.begin(), p_data.end(), m_p_image);
}


//-------------------------------------------------
void Image::loadASCII(const std::string& aFileName)
//-------------------------------------------------
{
	loadASCII(aFileName.data());
}


//------------------------------------------
void Image::saveASCII(const char* aFileName)
//------------------------------------------
{
	// Open the file
	std::ofstream output_file(aFileName);

	// The file is not open
	if (!output_file.is_open())
	{
		std::string error_message("The file (");
		error_message += aFileName;
		error_message += ") cannot be created";

		throw error_message;
	}

	// Write content to file
	float* p_data(m_p_image);
	for (unsigned int j(0); j < m_height; ++j)
	{
		for (unsigned int i(0); i < m_width; ++i)
		{
			output_file << *p_data++;

			// This is not the last pixel of the line
			if (i < m_width - 1)
			{
				output_file << " ";
			}
		}

		// This is not the last line
		if (j < m_height - 1)
		{
			output_file << std::endl;
		}
	}
}


//-------------------------------------------------
void Image::saveASCII(const std::string& aFileName)
//-------------------------------------------------
{
	saveASCII(aFileName.data());
}


//------------------------------------------------
bool Image::operator==(const Image& anImage) const
//------------------------------------------------
{
	if (m_width != anImage.m_width)
	{
		return (false);
	}

	if (m_height != anImage.m_height)
	{
		return (false);
	}

	float const * p_data1(m_p_image);
	float const * p_data2(anImage.m_p_image);
	for (unsigned int i(0); i < m_width * m_height; ++i)
	{
		if (std::abs(*p_data1++ - *p_data2++) > 1.0e-6)
		{
			return (false);
		}
	}

	return (true);
}


//------------------------------------------------
bool Image::operator!=(const Image& anImage) const
//------------------------------------------------
{
	return (!(operator==(anImage)));
}


// -------------ASSIGNMENT 2--------------------

//----------------------------------
float Image::getMeanValue() const
//----------------------------------
{
	float total = 0.0f;

	for (unsigned int i(0); i < m_width; i++)
	{
		for (unsigned int j(0); j < m_height; j++)
		{
			total += getPixel(i, j);
		}
	}

	return (total / getSize());
}


//------------------------------
float Image::getVariance(const float mean) const
//------------------------------
{
	//float image_mean = getMeanValue();

	float variance = 0;

	for (unsigned int i(0); i < m_width; i++)
	{
		for (unsigned int j(0); j < m_height; j++)
		{
			variance += pow((getPixel(i, j) - mean), 2);
		}
	}

	return (variance / (getSize()));
}


//-------------------------------
float Image::getDeviation(const float variance) const
//-------------------------------
{
	return (sqrt(variance));
}


//--------------------------
float Image::getSize() const
//--------------------------
{
	return (m_width * m_height);
}


//-------------------------------------------
float Image::getNCC(const Image & anImage) const
//-------------------------------------------
{
	if ((m_width != anImage.m_width) && (m_height != anImage.m_height))
	{
		throw "images must be of the same dimensions";
	}

	float this_image_mean = getMeanValue();
	float an_image_mean = anImage.getMeanValue();
	float this_image_deviation = getDeviation(getVariance(this_image_mean));
	float an_image_deviation = anImage.getDeviation(anImage.getVariance(an_image_mean));
	float NCC = 0;

	for (unsigned int i(0); i < m_width; i++)
	{
		for (unsigned int j(0); j < m_height; j++)
		{
			NCC += ((getPixel(i, j) - this_image_mean) * (anImage.getPixel(i, j) - an_image_mean))
				/ (this_image_deviation * an_image_deviation);
		}
	}

	return ((1 / getSize()) * (NCC));
}


//----------------------------------------------
float Image::getSAE(const Image & anImage) const
//----------------------------------------------
{
	float SAE = 0;

	for (unsigned int i(0); i< m_width; i++)
	{
		for (unsigned int j(0); j < m_height; j++)
		{
			SAE += sqrt(pow(getPixel(i, j) - anImage.getPixel(i, j), 2));
		}
	}

	return SAE;
}

//--------------------------------------------------------------------
void Image::getHistogram(unsigned int num_bins, const char* file_name)
//--------------------------------------------------------------------
{
	std::ofstream output_stream(file_name);

	if (!output_stream.is_open()) // The file is not open
	{
		std::string error_message("Cannot open file ");
		error_message += file_name;
		throw (error_message); // Throw an error
	}

	std::vector<unsigned int> histogram(num_bins);
	float min_val = getMinValue();
	float bin_size = float((getMaxValue() - min_val)) / num_bins;
	float pixel = 0.0f;
	output_stream << "Min_bin_value Count" << std::endl;

	for (unsigned int i(0); i < m_width; i++)
	{
		for (unsigned int j(0); j < m_height; j++)
		{
			pixel = getPixel(i, j);
			for (unsigned int k(0); k < num_bins; k++)
			{
				if (min_val + bin_size * (k) < pixel && pixel < min_val + bin_size * (k + 1))
				{
					histogram.at(k)++;
					k = num_bins;
				}
			}
		}
	}

	for (unsigned int i(0); i < num_bins; i++)
	{
		output_stream << min_val + bin_size * i << " " << histogram[i] << std::endl;
	}

	output_stream.close();
}


//----------------------------------
Image Image::useMedianFilter() const
//----------------------------------
{
	Image new_image(*this);
	std::vector<int> values;
	

	for (unsigned int i(1); i < m_width - 1; i++)
	{
		for (unsigned int j(1); j < m_height - 1; j++)
		{
			
			values.push_back(getPixel(i - 1, j - 1));
			values.push_back(getPixel(i, j - 1));
			values.push_back(getPixel(i + 1, j - 1));

			values.push_back(getPixel(i - 1, j));
			values.push_back(getPixel(i, j));
			values.push_back(getPixel(i + 1, j));

			values.push_back(getPixel(i - 1, j + 1));
			values.push_back(getPixel(i, j + 1));
			values.push_back(getPixel(i + 1, j + 1));

			std::sort(values.begin(), values.end());
			new_image.setPixel(i, j, (values[4]));
			values.clear();
		}
	}


	return (new_image);
}

//---------------------------------------------------------------
Image Image::useSpacialConvolution(std::vector<int> filter) const
//---------------------------------------------------------------
{
	if (filter.size() == 9)
		filter.push_back(1);

	
		throw "Filter must have 10 elements";

	if (filter[9] == 0)
		filter[9] = 1;
	
	Image new_image(*this);

	for (unsigned int i(1); i < m_width - 1; i++)
	{
		for (unsigned int j(1); j < m_height - 1; j++)
		{
			new_image.setPixel(i, j, 
				(getPixel(i - 1, j - 1) * filter[0] + getPixel(i, j - 1) * filter[1] + getPixel(i + 1, j - 1) * filter[2] +
				getPixel(i - 1, j) * filter[3] + getPixel(i, j) * filter[4] + getPixel(i + 1, j) * filter[5] +
				getPixel(i - 1, j + 1) * filter[6] + getPixel(i, j + 1) * filter[7] + getPixel(i + 1, j + 1) * filter[8]) 
				* 1 / filter[9]);
		}
	}

	return (new_image);
}


//------------------------------------
Image Image::useGaussianFilter() const
//------------------------------------
{
	std::vector<int> gaussian_filter = { 1, 2, 1, 2, 4, 2, 1, 2, 1, 16};

	Image new_image(useSpacialConvolution(gaussian_filter));

	return (new_image);
}


//------------------------------
Image Image::detectEdges() const
//------------------------------
{
	std::vector<int> prewitt_x = {1, 0, -1, 1, 0, -1, 1, 0, -1};
	std::vector<int> prewitt_y = {1, 1, 1, 0, 0, 0, -1, -1, -1};

	Image new_image(useSpacialConvolution(prewitt_x) + useSpacialConvolution(prewitt_y));

	return (new_image);
}


//-------------------------------
Image Image::sharpenImage() const
//-------------------------------
{
	std::vector<int> sharpen_filter = {0, -1, 0, -1, 5, -1, 0, -1, 0};

	Image new_image(useSpacialConvolution(sharpen_filter));

	return (new_image);
}

//-----------------------------------
Image Image::

useBoxBlurFilter() const
//-----------------------------------
{
	std::vector<int> box_blur_filter = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 9};

	Image new_image(useSpacialConvolution(box_blur_filter));

	return (new_image);
}




//-----------------------------------------------
Image Image::operator<=(const float aValue) const
//-----------------------------------------------
{
	Image new_image(*this);

	for (unsigned int i(0); i < m_width; i++)
	{
		for (unsigned int j(0); j < m_height; j++)
		{
			if (getPixel(i, j) >= aValue)
			{
				new_image.setPixel(i, j, 1);
			}
			else
			{
				new_image.setPixel(i, j, 0);
			}
		}
	}

	return (new_image);
}


//---------------------------------------------------------------------
Image Image::blendImage(const Image& anImage, const float aValue) const
//---------------------------------------------------------------------
{
	if ((aValue < 0) || (aValue > 1))
	{
		throw "Threshold value needs to be between 0 and 1";
	}

	Image first_image(*this);
	Image second_image(anImage);

	return (first_image * (1 - aValue) + second_image * aValue);
}


//----------------------------------------------
Image Image::resizeImage(const int aValue) const
//----------------------------------------------
{
	Image new_image(m_width * aValue, m_height * aValue);
	new_image.m_p_image = (new float[new_image.m_width * new_image.m_height]);

	for (unsigned int i(0); i < new_image.m_width; i+=2)
	{
		for (unsigned int j(0); j < new_image.m_height; j+=2)
		{
			new_image.setPixel(i, j, getPixel(i / aValue, j / aValue));
		}
	}

	new_image = new_image.interpolateX();
	new_image = new_image.interpolateY();
	new_image = new_image.interpolateXY();

	return (new_image);
}

Image Image::interpolateX() const
{
	Image new_image(*this);

	for (unsigned int i(1); i < m_width - 1; i += 2)
	{
		for (unsigned int j(0); j < m_height - 1; j += 2)
		{
			new_image.setPixel(i, j, getPixel(i - 1, j) + (i - (i - 1)) * (getPixel(i + 1, j) - getPixel(i - 1, j)) / ((i + 1) - (i - 1)));
		}
	}

	return (new_image);
}

Image Image::interpolateY() const
{
	Image new_image(*this);

	for (unsigned int i(0); i < new_image.m_width - 1; i += 2)
	{
		for (unsigned int j(1); j < new_image.m_height - 1; j += 2)
		{
			new_image.setPixel(i, j, new_image.getPixel(i, j - 1) + (j - (j - 1)) * (new_image.getPixel(i, j + 1) - new_image.getPixel(i, j - 1)) / ((j + 1) - (j - 1)));
		}
	}

	return (new_image);
}

Image Image::interpolateXY() const
{
	Image new_image(*this);

	for (unsigned int i(1); i < new_image.m_width - 1; i += 2)
	{
		for (unsigned int j(1); j < new_image.m_height - 1; j += 2)
		{
			new_image.setPixel(i, j, new_image.getPixel(i, j - 1) + (j - (j - 1)) * (new_image.getPixel(i, j + 1) - new_image.getPixel(i, j - 1)) / ((j + 1) - (j - 1)));
		}
	}

	return (new_image);
}


