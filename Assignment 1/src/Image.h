#ifndef IMAGE_H
#define IMAGE_H


/**
********************************************************************************
*
*	@file		Image.h
*
*	@brief		BRIEF DESCRIPTION ABOUT THE CONTENT OF THE FILE.
*
*	@version	1.0
*
*   @todo       Add an accessor on the width of the image
*   @todo       Add an accessor on the height of the image;
*   @todo       Add a method returning the aspect ratio;
*   @todo       Add a method to set the value of a given pixel;
*   @todo       Add a method returning the value of a given pixel;
*   @todo       Add a method to read an image from a RAW file;
*   @todo       Add a method to write an image from a RAW file;
*   @todo       Add a method returning the smallest value in the image;
*   @todo       Add a method normlising the image between 0 and 1;
*   @todo       Add a method returning a region of interest.
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
