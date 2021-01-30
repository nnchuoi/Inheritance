#pragma once
#include <iostream>
#include <string>
#include "File.h"

// enum class makes enumerations both strongly typed and strongly scoped
enum class Encoding {ASCII, Unicode};

std::ostream & operator<<(std::ostream & out, const Encoding  & e)  {
	return out << ((e == Encoding::ASCII) ? "ASCII" : "Unicode");
}
		
class Text : public File {
	private :
		Encoding encoding;
	public :	
		Text(const std::string & n, const std::string & e, unsigned int s, Encoding en) : File(n, e, s), encoding {en} {}
		unsigned int getCompressedSize() const override { return (encoding == Encoding::ASCII ? 0.5 : 0.6) * size;}	
	friend std::ostream & operator<<(std::ostream & out, const Text & t)  {
		out << static_cast<const File &>(t) << " and encoding "<< t.encoding << std::endl;
		return out;
	}
};
