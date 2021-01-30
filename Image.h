#pragma once
#include <iostream>
#include <string>
#include "File.h"

class Image : public File {
	private :
		unsigned int width;
		unsigned int height; 
	public :
		Image(const std::string & n, const std::string & e, unsigned int s, unsigned int w, unsigned int h) : File(n, e, s), width {w}, height {h} {}
		unsigned int getCompressedSize() const override { return width*height/2;}
	friend std::ostream & operator<<(std::ostream & out, const Image  & i) {
		out << static_cast<const File &>(i) << " and width "<< i.width << " and height " << i.height << std::endl;
		return out;
	}
};
