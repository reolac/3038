/**
********************************************************************************
*
*	@file		Image.cpp
*
*	@brief		BRIEF DESCRIPTION ABOUT THE CONTENT OF THE FILE.
*
*	@version	1.0
*
*	@date		27/10/2015
*
*	@author		Michael Smith
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

#include "Image.h"


//------------------
Image::Image():
//------------------
        m_width(0),
        m_height(0),
        m_p_image(0)
//------------------
{ // NOTHIND TO DO HERE
}


//--------------------------------
Image::Image(const Image& anImage):
//--------------------------------
m_width(anImage.m_width),
m_height(anImage.m_height),
m_p_image(anImage.m_p_image)
{
    // IT IS THE CONSTRUCTOR, USE AN INITIALISATION LIST
	// PUT CODE HERE TO COPY THE DATA
}


//-------------
Image::~Image()
//-------------
{
    // ADD CODE HERE TO RELEASE THE MEMORY
	if (m_p_image) delete [] m_p_image;
}


//-------------------
void Image::destroy()
//-------------------
{
    // Memory has been dynamically allocated
    if (m_p_image)
    {
        // Release the memory
        delete [] m_p_image;
    
        // Make sure the pointer is reset to NULL
        m_p_image = 0;
    }
    
    // There is no pixel in the image
    m_width  = 0;
    m_height = 0;
}


//-------------------------------------------
Image& Image::operator=(const Image& anImage)
//-------------------------------------------
{
    // ADD CODE HERE TO COPY THE DATA

	m_width = anImage.m_width;
	m_height = anImage.m_height;

	if (m_p_image) delete[] m_p_image;
	
	float* m_p_copy = new float[m_width * m_height];
	m_p_image = m_p_copy;

	float* p_copy(anImage.m_p_image);

	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		*m_p_copy++ = *p_copy++;
	}

	return (*this);

}


//------------------------------------------
Image Image::operator+(const Image& anImage)
//------------------------------------------
{
    // ADD CODE HERE TO ADD TWO IMAGES TO EACH OTHER,
    // AND RETURN THE RESULTING IMAGE
	Image temp;

	temp.m_height;
	temp.m_width;

	float m_width2 = anImage.m_width;
	float m_height2 = anImage.m_height;
	float* m_p_image2 = anImage.m_p_image;

	


	//float* m_p_image = new float[m_width * m_height];

	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] = m_p_image[i] + m_p_image2[i];
	}

	return (*this);
}


//------------------------------------------
Image Image::operator-(const Image& anImage)
//------------------------------------------
{
    // ADD CODE HERE TO SUBTRACT AN anImage TO THE CURRENT ONE,
    // AND RETURN THE RESULTING IMAGE

	if (m_p_image) delete[] m_p_image;

	float m_width1 = anImage.m_width;
	float m_height1 = anImage.m_height;
	float* m_p_image1 = anImage.m_p_image;

	float m_width2 = anImage.m_width;
	float m_height2 = anImage.m_height;
	float* m_p_image2 = anImage.m_p_image;



	//float* m_p_image = new float[m_width * m_height];

	for (unsigned int i(0); i < m_width * m_height; i++)
	{
		m_p_image[i] = m_p_image1[i] - m_p_image2[i];
	}

	return (*this);
}


//--------------------------------------------
Image& Image::operator+=(const Image& anImage)
//--------------------------------------------
{
    // ADD CODE HERE TO ADD TWO IMAGES TO EACH OTHER,
    // SAVE THE RESULT IN THE CURRENT IMAGE,
    // AND RETURN A REFERENCE TO THE CURRENT IMAGE
}


//--------------------------------------------
Image& Image::operator-=(const Image& anImage)
//--------------------------------------------
{
    // ADD CODE HERE TO SUBTRACT AN anImage TO THE CURRENT ONE,
    // SAVE THE RESULT IN THE CURRENT IMAGE,
    // AND RETURN A REFERENCE TO THE CURRENT IMAGE
}


//----------------------------------
Image Image::operator+(float aValue)
//----------------------------------
{
    // ADD CODE HERE TO ADD aValue TO EACH PIXEL OF THE CURRENT IMAGE,
    // AND RETURN THE RESULTING IMAGE
}


//----------------------------------
Image Image::operator-(float aValue)
//----------------------------------
{
    // ADD CODE HERE TO SUBTRACT aValue FROM EACH PIXEL OF THE CURRENT IMAGE,
    // AND RETURN THE RESULTING IMAGE
}


//----------------------------------
Image Image::operator*(float aValue)
//----------------------------------
{
    // ADD CODE HERE TO MULTIPLY aValue TO EACH PIXEL OF THE CURRENT IMAGE,
    // AND RETURN THE RESULTING IMAGE
}


//----------------------------------
Image Image::operator/(float aValue)
//----------------------------------
{
    // ADD CODE HERE TO DIVIDE EACH PIXEL OF THE CURRENT IMAGE BY aValue,
    // AND RETURN THE RESULTING IMAGE
}


//-----------------------------------
Image& Image::operator+=(float aValue)
//-----------------------------------
{
    // ADD CODE HERE TO ADD aValue TO EACH PIXEL OF THE CURRENT IMAGE,
    // SAVE THE RESULT IN THE CURRENT IMAGE,
    // AND RETURN A REFERENCE TO THE CURRENT IMAGE
}


//------------------------------------
Image& Image::operator-=(float aValue)
//------------------------------------
{
    // ADD CODE HERE TO SUBTRACT aValue FROM EACH PIXEL OF THE CURRENT IMAGE,
    // SAVE THE RESULT IN THE CURRENT IMAGE,
    // AND RETURN A REFERENCE TO THE CURRENT IMAGE
}


//------------------------------------
Image& Image::operator*=(float aValue)
//------------------------------------
{
    // ADD CODE HERE TO DIVIDE EACH PIXEL OF THE CURRENT IMAGE BY aValue
    // SAVE THE RESULT IN THE CURRENT IMAGE,
    // AND RETURN A REFERENCE TO THE CURRENT IMAGE
}


//------------------------------------
Image& Image::operator/=(float aValue)
//------------------------------------
{
    // ADD CODE HERE TO SUBTRACT aValue FROM EACH PIXEL OF THE CURRENT IMAGE,
    // SAVE THE RESULT IN THE CURRENT IMAGE,
    // AND RETURN A REFERENCE TO THE CURRENT IMAGE
}


//----------------------
Image Image::operator!()
//----------------------
{
    // ADD CODE HERE TO COMPUTE THE NEGATIVE IMAGE OF THE CURRENT IMAGE,
    // AND RETURN THE RESULTING IMAGE
}


//------------------------------
float Image::getMaxValue() const
//------------------------------
{
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
            // Build the error message
            std::stringstream error_message;
            error_message << "Invalid file (\"" << aFileName << "\")";
        
            // Throw an error
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
