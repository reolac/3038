#ifndef IMAGE_H
#define IMAGE_H


/**
********************************************************************************
*
*   @file       Image.h
*
*   @brief      Class to handle a greyscale image.
*
*   @version    1.0
*
*   @date       16/12/2016
*
*   @author     Michael Smith
*
*
********************************************************************************
*/

//******************************************************************************
//  Include
//******************************************************************************
#include <string>


//==============================================================================
/**
*   @class  Image
*   @brief  Image is a class to manage a greyscale image.
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
	/// Constructor from an array.
	/**
	* @param apData: the array to copy
	* @param aWidth: the width of the image
	* @param aHeight: the height of the image
	*/
	//------------------------------------------------------------------------
	Image(const float* apData,
		unsigned int aWidth,
		unsigned int aHeight);


	//------------------------------------------------------------------------
	/// Constructor to build a black image.
	/**
	* @param aWidth: the width of the image
	* @param aHeight: the height of the image
	*/
	//------------------------------------------------------------------------
	Image(unsigned int aWidth,
		unsigned int aHeight);


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
	/// Compute a region of interest (ROI).
	/**
	* @param i: the position of the first pixel of the ROI along the horizontal axis
	* @param j: the position of the first pixel of the ROI along the vertical axis
	* @param aWidth: the width of the ROI (in number of pixels)
	* @param aHeight: the height of the ROI (in number of pixels)
	* @return the ROI
	*/
	//------------------------------------------------------------------------
	Image getROI(unsigned int i,
		unsigned int j,
		unsigned int aWidth,
		unsigned int aHeight) const;


	//------------------------------------------------------------------------
	/// Set a pixel.
	/**
	* @param i: the position of the pixel along the horizontal axis
	* @param j: the position of the pixel along the vertical axis
	* @param aValue: the new pixel value
	*/
	//------------------------------------------------------------------------
	void setPixel(unsigned int i, unsigned int j, float aValue);


	//------------------------------------------------------------------------
	/// Accessor on a pixel value.
	/**
	* @param i: the position of the pixel along the horizontal axis
	* @param j: the position of the pixel along the vertical axis
	* @return the pixel value
	*/
	//------------------------------------------------------------------------
	float getPixel(unsigned int i, unsigned int j) const;


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
	/// Compute the aspect ratio
	/**
	* @return the aspect ratio
	*/
	//------------------------------------------------------------------------
	float getAspectRatio() const;


	//------------------------------------------------------------------------
	/// Number of pixels along the horizontal axis
	/**
	* @return the width
	*/
	//------------------------------------------------------------------------
	unsigned int getWidth() const;


	//------------------------------------------------------------------------
	/// Number of pixels along the vertical axis
	/**
	* @return the height
	*/
	//------------------------------------------------------------------------
	unsigned int getHeight() const;


	//------------------------------------------------------------------------
	/// Compute the minimum pixel value in the image
	/**
	* @return the minimum pixel
	*/
	//------------------------------------------------------------------------
	float getMinValue() const;


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
	/// Normalise the image between 0 and 1
	//------------------------------------------------------------------------
	void normalise();


	//------------------------------------------------------------------------
	/// Normalize the image between 0 and 1
	//------------------------------------------------------------------------
	void normalize();


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
	/// Load an image from a Raw file
	/**
	* @param aFileName: the name of the file to load
	*/
	//------------------------------------------------------------------------
	void loadRaw(const char* aFileName,
		unsigned int aWidth,
		unsigned int aHeight);


	//------------------------------------------------------------------------
	/// Load an image from a Raw file
	/**
	* @param aFileName: the name of the file to load
	*/
	//------------------------------------------------------------------------
	void loadRaw(const std::string& aFileName,
		unsigned int aWidth,
		unsigned int aHeight);


	//------------------------------------------------------------------------
	/// Save the image in a Raw file
	/**
	* @param aFileName: the name of the file to write
	*/
	//------------------------------------------------------------------------
	void saveRaw(const char* aFileName);


	//------------------------------------------------------------------------
	/// Save the image in a Raw file
	/**
	* @param aFileName: the name of the file to write
	*/
	//------------------------------------------------------------------------
	void saveRaw(const std::string& aFileName);


	//------------------------------------------------------------------------
	/// Load an image from an ASCII file
	/**
	* @param aFileName: the name of the file to load
	*/
	//------------------------------------------------------------------------
	void loadASCII(const char* aFileName);


	//------------------------------------------------------------------------
	/// Load an image from an ASCII file
	/**
	* @param aFileName: the name of the file to load
	*/
	//------------------------------------------------------------------------
	void loadASCII(const std::string& aFileName);


	//------------------------------------------------------------------------
	/// Save the image in an ASCII file
	/**
	* @param aFileName: the name of the file to write
	*/
	//------------------------------------------------------------------------
	void saveASCII(const char* aFileName);


	//------------------------------------------------------------------------
	/// Save the image in an ASCII file
	/**
	* @param aFileName: the name of the file to write
	*/
	//------------------------------------------------------------------------
	void saveASCII(const std::string& aFileName);


	//------------------------------------------------------------------------
	/// Operator Equal to
	/**
	* @param anImage: the image to compare with
	* @return true if the images are similar,
	*         false if they are different
	*/
	//------------------------------------------------------------------------
	bool operator==(const Image& anImage) const;


	//------------------------------------------------------------------------
	/// Operator Not equal to
	/**
	* @param anImage: the image to compare with
	* @return true if the images are different,
	*         false if they are similar
	*/
	//------------------------------------------------------------------------
	bool operator!=(const Image& anImage) const;

	Image operator<=(const float aValue) const;

	Image Image::blendImage(const Image& anImage, const float aValue) const;

	Image Image::resizeImage(const int aValue) const;

	Image Image::interpolateX() const;

	Image Image::interpolateY() const;

	Image Image::interpolateXY() const;

	float Image::getNCC(const Image& anImage) const;

	float Image::getSAE(const Image& anImage) const;

	float Image::getMeanValue() const;

	float Image::getVariance(const float mean) const;

	float Image::getDeviation(const float variance) const;

	float Image::getSize() const;

	void Image::getHistogram(unsigned int aNumberOfBins, const char* file_name);

	Image Image::useMedianFilter() const;

	Image Image::useSpacialConvolution(std::vector<int>) const;

	Image Image::useGaussianFilter() const;

	Image Image::detectEdges() const;

	Image Image::sharpenImage() const;

	Image Image::useBoxBlurFilter() const;





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
