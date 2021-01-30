#pragma once
#include <iostream>
#include <string>

class File {
	protected :
		std::string name;
		std::string extension;
		unsigned int size;
	public : 
		File(const std::string & n, const std::string & e, unsigned int s) : name {n}, extension {e}, size {s} {}
		virtual ~File() {}
		unsigned int getSize() const {return size;}
		virtual unsigned int getCompressedSize() const = 0;
	friend std::ostream & operator<<(std::ostream & out, const File  & f) {
		out << "File " << f.name << "." << f.extension << " of size " << f.size;
		return out;
	}
};

