#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage()
{
	pixels = new std::vector<std::vector<std::vector<RGB>>>(); //No Height Yet
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	delete pixels;
	pixels = other.pixels;
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	std::vector< RGB > rgb(1); // vector of 1 rgb
	std::vector< std::vector< RGB > > vec_2d(width, rgb); // [][y][RGB]

	pixels = new std::vector<std::vector<std::vector<RGB>>>(height, vec_2d); //[x][y][RGB]
}

RGBImageStudent::~RGBImageStudent() {
	delete pixels;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);

	delete pixels;
	std::vector< RGB > rgb(1); // vector of 1 rgb
	std::vector< std::vector< RGB > > vec_2d(width, rgb); // [][y][RGB]

	pixels = new std::vector<std::vector<std::vector<RGB>>>(height, vec_2d); //[x][y][RGB]
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	//Clean deletion
	delete pixels;
	//Creation
	pixels = other.pixels;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixels[x][y][0] = {pixel};
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int throwError = 0, e = 1 / throwError;

	int x = (i % RGBImage::getHeight());
	int y = ((i - x) / RGBImage::getWidth());

	pixels[x][y][0] = { pixel };
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	
	return pixels[x][y][0][0];
}

RGB RGBImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	
	int x = (i % RGBImage::getHeight());
	int y = ((i - x) / RGBImage::getWidth());

	return pixels[x][y][0][0];
}