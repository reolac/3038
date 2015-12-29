#ifndef IMAGE_H
#define IMAGE_H


/**
********************************************************************************
*
*	@file		Image.h
*
*	@brief		This file contains only the function declarions for the Image class.
*
*	@version	1.0
*   
*	@date		9/11/2015
*
*	@author		Michael. P. J. Smith
*
*
********************************************************************************
*/

//******************************************************************************
//	Include
//******************************************************************************
#include <string>


//==============================================================================
/**
*	@class	Image
*	@brief	Image is a class to manage a greyscale image.
*/
//==============================================================================
class Image
//------------------------------------------------------------------------------
{
//******************************************************************************
public:
    //--------------------------------------------------------------------------
    /// Default constructor.
    //--------------------------------------------------------------------------
    Image();


    //------------------------------------------------------------------------
    /// Copy constructor.
    /**
    * @param anImage: the image to copy
    */
    //------------------------------------------------------------------------
    Image(const Image& anImage);
    
    
    //------------------------------------------------------------------------
    /// Destructor.
    //------------------------------------------------------------------------
    ~Image();
    
    
    //------------------------------------------------------------------------
    /// Assignment operator (also called copy operator).
    /**
    * @param anImage: the image to copy
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator=(const Image& anImage);
    
    
    //------------------------------------------------------------------------
    /// Release the memory.
    //------------------------------------------------------------------------
    void destroy();
    
    
    //------------------------------------------------------------------------
    /// Addition operator. Add anImage
    /**
    * @param anImage: the image to add
    * @return the resulting image
    */
    //------------------------------------------------------------------------
    Image operator+(const Image& anImage);
    
    
    //------------------------------------------------------------------------
    /// Subtraction operator. Add anImage
    /**
    * @param anImage: the image to subtract
    * @return the resulting image
    */
    //------------------------------------------------------------------------
    Image operator-(const Image& anImage);


    //------------------------------------------------------------------------
    /// Addition assignment operator. Add anImage
    /**
    * @param anImage: the image to add
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator+=(const Image& anImage);


    //------------------------------------------------------------------------
    /// Subraction assignment operator. Add anImage
    /**
    * @param anImage: the image to subtract
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator-=(const Image& anImage);
    
    
    //------------------------------------------------------------------------
    /// Addition operator. Add aValue to every pixel of the image
    /**
    * @param aValue: the value to add
    * @return the resulting image
    */
    //------------------------------------------------------------------------
    Image operator+(float aValue);


    //------------------------------------------------------------------------
    /// Subtraction operator. Subtract aValue to every pixel of the image
    /**
    * @param aValue: the value to subtract
    * @return the resulting image
    */
    //------------------------------------------------------------------------
    Image operator-(float aValue);


    //------------------------------------------------------------------------
    /// Multiplication operator. Multiply every pixel of the image by aValue
    /**
    * @param aValue: the value for the multiplication
    * @return the resulting image
    */
    //------------------------------------------------------------------------
    Image operator*(float aValue);
    
    
    //------------------------------------------------------------------------
    /// Division operator. Divide every pixel of the image by aValue
    /**
    * @param aValue: the value for the division
    * @return the resulting image
    */
    //------------------------------------------------------------------------
    Image operator/(float aValue);


    //------------------------------------------------------------------------
    /// Addition operator. Add aValue to every pixel of the image
    /**
    * @param aValue: the value to add
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator+=(float aValue);


    //------------------------------------------------------------------------
    /// Subtraction operator. Subtract aValue to every pixel of the image
    /**
    * @param aValue: the value to subtract
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator-=(float aValue);


    //------------------------------------------------------------------------
    /// Multiplication operator. Multiply every pixel of the image by aValue
    /**
    * @param aValue: the value for the multiplication
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator*=(float aValue);


    //------------------------------------------------------------------------
    /// Division operator. Divide every pixel of the image by aValue
    /**
    * @param aValue: the value for the division
    * @return the updated version of the current image
    */
    //------------------------------------------------------------------------
    Image& operator/=(float aValue);


    //------------------------------------------------------------------------
    /// Negation operator. Compute the negative of the current image.
    /**
    * @return the negative image
    */
    //------------------------------------------------------------------------
    Image operator!();
    

    //------------------------------------------------------------------------
    /// Compute the maximum pixel value in the image
    /**
    * @return the maximum pixel
    */
    //------------------------------------------------------------------------
    float getMaxValue() const;
    

    //------------------------------------------------------------------------
    /// Add aShiftValue to every pixel, then multiply every pixel
    /// by aScaleValue
    /**
    * @param aShiftValue: the shift parameter of the filter
    * @param aScaleValue: the scale parameter of the filter
    */
    //------------------------------------------------------------------------
    void shiftScaleFilter(float aShiftValue, float aScaleValue);
    
    
    //------------------------------------------------------------------------
    /// Load an image from a PGM file
    /**
    * @param aFileName: the name of the file to load
    */
    //------------------------------------------------------------------------
    void loadPGM(const char* aFileName);
    
    
    //------------------------------------------------------------------------
    /// Load an image from a PGM file
    /**
    * @param aFileName: the name of the file to load
    */
    //------------------------------------------------------------------------
    void loadPGM(const std::string& aFileName);
    
    
    //------------------------------------------------------------------------
    /// Save the image in a PGM file
    /**
    * @param aFileName: the name of the file to write
    */
    //------------------------------------------------------------------------
    void savePGM(const char* aFileName);
    
    
    //------------------------------------------------------------------------
    /// Save the image in a PGM file
    /**
    * @param aFileName: the name of the file to write
    */
    //------------------------------------------------------------------------
    void savePGM(const std::string& aFileName);


	//------------------------------------------------------------------------
	/// Accesses and returns the width of the current image
	/**
	* @return the total width
	*/
	//------------------------------------------------------------------------
	unsigned int getWidth();


	//------------------------------------------------------------------------
	/// Accesses and returns the height of the current image
	/**
	* @return the total height
	*/
	//------------------------------------------------------------------------
	unsigned int getHeight();


	//------------------------------------------------------------------------
	/// Accesses and returns the aspect ratio for the current image
	/**
	* @return the total height
	*/
	//------------------------------------------------------------------------
	float getAspectRatio() const;

    
	//------------------------------------------------------------------------
	/// Accesses a pixel element and returns its value
	/**
	* @param i represents the column index
	* @param j represents the row index
	* @return the value of that pixel element
	*/
	//------------------------------------------------------------------------
	unsigned char getPixel(unsigned int i, unsigned int j) const;


	//------------------------------------------------------------------------
	/// Accesses a pixel element and changes it to a different value
	/**
	* @param i represents the column index
	* @param j represents the row index
	* @param aValue the value you are setting the pixel to
	*/
	//------------------------------------------------------------------------
	void setPixel(unsigned int i, unsigned int j, unsigned char aValue);


	//------------------------------------------------------------------------
	/// Load the image from a RAW file
	/**
	* @param aFileName: the name of the file to read
	*/
	//------------------------------------------------------------------------
	void loadRAW(const std::string& aFileName);


	//------------------------------------------------------------------------
	/// Save the image in a RAW file
	/**
	* @param aFileName: the name of the file to write
	*/
	//------------------------------------------------------------------------
	void saveRAW(const std::string& aFileName);


	//------------------------------------------------------------------------
	/// Compute the minimum pixel value in the image
	/**
	* @return the minimum pixel
	*/
	//------------------------------------------------------------------------
	float getMinValue() const;


	//------------------------------------------------------------------------
	/// Normalises the image between 0 and 1
	/**
	* 
	*/
	//------------------------------------------------------------------------
	void normaliseImage() const;

	//------------------------------------------------------------------------
	/// Gets a region of interest from the  image
	/**
	* @param startingX region starting x coordinate
	* @param endingX region ending x coordinate
	* @param startingY region starting y coordinate
	* @param endingY region ending y coordinate
	*/
	//------------------------------------------------------------------------
	Image getROI(unsigned int startingX, unsigned int endingX, unsigned int startingY, unsigned int endingY);


//******************************************************************************
private:
    /// Number of pixel along the horizontal axis
    unsigned int m_width;


    /// Number of pixel along the vertical axis
    unsigned int m_height;

    
    /// The pixel data
    float* m_p_image;
};

#endif
