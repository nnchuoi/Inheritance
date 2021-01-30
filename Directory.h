#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "File.h"

class Directory {
	private :
		std::string name;
		std::vector<File *> files;
	public : 
		Directory(const std::string & n) : name {n} {}
		void addFile(File * f) {files.push_back(f);}
		std::vector<File *> getFiles() const {return files;}
	friend std::ostream & operator<<(std::ostream & out, const Directory  & d) {
		out << "Directory " << d.name  << std::endl;
		for (auto f : d.files) {
			out << *f << std::endl; // no runtime polymorphism here
		}
		return out;
	}
};
