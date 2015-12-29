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

	//------------------------------------------------------------------------
	/// Operator Equal or greater than
	/**
	* @return 1 for pixels which are, 0 for pixels which are not,
	*         
	*/
	//------------------------------------------------------------------------
	Image operator<=(const float aValue) const;


	//------------------------------------------------------------------------
	/// Blend this image with another image
	/**
	* @param anImage: the image to compare with
	* @param aValue: the threshold value of each image (between 0 and 1)
	* @return the blended image of this and anImage
	*
	*/
	//------------------------------------------------------------------------
	Image Image::blendImage(const Image& anImage, const float aValue) const;


	//------------------------------------------------------------------------
	/// Resizes the image to the set size
	/**
	* @param aValue the scale to resize the image by
	* @return the resized image
	*
	*/
	//------------------------------------------------------------------------
	Image Image::resizeImage(const int aValue) const;

	//------------------------------------------------------------------------
	/// Interpolates along the X axis of the image
	/**
	* @return image with all x values interpolated
	*
	*/
	//------------------------------------------------------------------------
	Image Image::interpolateX() const;


	//------------------------------------------------------------------------
	/// Interpolates along the Y axis of the image
	/**
	* @return image with all y values interpolated
	*
	*/
	//------------------------------------------------------------------------
	Image Image::interpolateY() const;


	//------------------------------------------------------------------------
	/// Interpolates along the XY axis of the image
	/**
	* @return image with all xy values interpolated
	*
	*/
	//------------------------------------------------------------------------
	Image Image::interpolateXY() const;

	//------------------------------------------------------------------------
	/// Gets the NCC between this image and anImage
	/**
	* @param anImage: the image to compare with
	* @return the NCC between this and anImage
	*
	*/
	//------------------------------------------------------------------------
	float Image::getNCC(const Image& anImage) const;


	//------------------------------------------------------------------------
	/// Gets the SAE between this image and anImage
	/**
	* @param anImage: the image to compare with
	* @return the SAE between this and anImage
	*
	*/
	//------------------------------------------------------------------------
	float Image::getSAE(const Image& anImage) const;


	//------------------------------------------------------------------------
	/// Gets the average value of the image
	/**
	* @return the average value of the image
	*
	*/
	//------------------------------------------------------------------------
	float Image::getMeanValue() const;

	//------------------------------------------------------------------------
	/// Gets the variance of the image
	/**
	* @param mean the mean of the image
	* @return the variance of the image
	*
	*/
	//------------------------------------------------------------------------
	float Image::getVariance(const float mean) const;


	//------------------------------------------------------------------------
	/// Gets the deviation of the image
	/**
	* @param variance the variance of the image
	* @return the variance of the deviation
	*
	*/
	//------------------------------------------------------------------------
	float Image::getDeviation(const float variance) const;


	//------------------------------------------------------------------------
	/// Gets the total size of the image
	/**
	* @return the size of the image
	*
	*/
	//------------------------------------------------------------------------
	float Image::getSize() const;


	//------------------------------------------------------------------------
	/// Computes and saves an intensity histogram of the image
	/**
	* @param aNumberOfBins the amount of bins for the histogram
	* @param file_name the name/location of the file to save it to
	* @return the size of the image
	*
	*/
	//------------------------------------------------------------------------
	void Image::getHistogram(unsigned int aNumberOfBins, const char* file_name);


	//------------------------------------------------------------------------
	/// Applys the median filter to the image
	/**
	* @return an median filtered image
	*
	*/
	//------------------------------------------------------------------------
	Image Image::useMedianFilter() const;

	//------------------------------------------------------------------------
	/// Applys a spacial convolution filter to the image
	/**
	* @param filter a vector to fill with 3 by 3 filter values
	* @return a spacial convolution filtered image
	*
	*/
	//------------------------------------------------------------------------
	Image Image::useSpacialConvolution(std::vector<int> filter) const;


	//------------------------------------------------------------------------
	/// Applys the gaussian filter to the image
	/**
	* @return a gaussian filtered image
	*
	*/
	//------------------------------------------------------------------------
	Image Image::useGaussianFilter() const;


	//------------------------------------------------------------------------
	/// Detects the edges of the image
	/**
	* @return an image showing its edges
	*
	*/
	//------------------------------------------------------------------------
	Image Image::detectEdges() const;


	//------------------------------------------------------------------------
	/// Applys the sharpening filter to the image
	/**
	* @return a sharpen filtered image
	*
	*/
	//------------------------------------------------------------------------
	Image Image::sharpenImage() const;


	//------------------------------------------------------------------------
	/// Applys the box blur filter to the image
	/**
	* @return a box blur filtered image
	*
	*/
	//------------------------------------------------------------------------
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
