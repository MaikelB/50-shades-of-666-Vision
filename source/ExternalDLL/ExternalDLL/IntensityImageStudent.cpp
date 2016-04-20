#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixels = other.pixels;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	//TODO: Initialize pixel storage
	std::vector< Intensity > intensity(1); // vector of 1 intensity
	std::vector< std::vector< Intensity > > vec_2d(width, intensity); // [][y][Intensity]

	pixels = new std::vector<std::vector<std::vector<Intensity>>>(height, vec_2d); //[x][y][Intensity]
	
}

IntensityImageStudent::~IntensityImageStudent() {
	delete pixels;
}

void IntensityImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	IntensityImage::set(width, height);

	delete pixels;
	std::vector< Intensity > intensity(1); // vector of 1 intensity
	std::vector< std::vector< Intensity > > vec_2d(width, intensity); // [][y][Intensity]

	pixels = new std::vector<std::vector<std::vector<Intensity>>>(height, vec_2d); //[x][y][Intensity]


}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete pixels;
	pixels = other.pixels;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixels[x][y][0] = { pixel };
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int x = (i % IntensityImage::getHeight());
	int y = ((i - x) / IntensityImage::getWidth());
	pixels[x][y][0] = { pixel };
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixels[x][y][0][0];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int x = (i % IntensityImage::getHeight());
	int y = ((i - x) / IntensityImage::getWidth());

	return pixels[x][y][0][0];
}