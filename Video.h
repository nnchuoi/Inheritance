#pragma once
#include <iostream>
#include <string>
#include "File.h"

class Video : public File {
	private :
		unsigned int duration;
	public :
		Video(const std::string & n, const std::string & e, unsigned int s, unsigned int d) : File(n, e, s), duration {d} {};
		unsigned int getCompressedSize() const override { return 0.8*duration;};
	friend std::ostream & operator<<(std::ostream & out, const Video  & v)  {
		out << static_cast<const File &>(v) << " and duration "<< v.duration << std::endl;
		return out;
	}	
};
