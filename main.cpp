#include <iostream>
#include "Directory.h"
#include "File.h"
#include "Image.h"
#include "Text.h"
#include "Video.h"

int main() {
	Text t("test","txt", 50, Encoding::ASCII);
	Image i("test", "jpeg", 800, 40, 10);
	Video v1("test", "mpeg", 4500, 3000);
	File * v2 = new Video("test", "mp3", 30000, 2000);  // just to try a pointer with dynamic allocation
	std::cout << t;
	std::cout << i;
	std::cout << v1;
	std::cout << *v2;
	
	Directory d("data");
	d.addFile(&t);
	d.addFile(&i);
	d.addFile(&v1);
	d.addFile(v2);
	std::cout << d;
	
	// compute average compressed rate
	double rate = 0.0;
	for (auto f : d.getFiles()) {
		rate += static_cast<double>(f->getCompressedSize())/f->getSize(); // polymorphism via virtual function and inheritance
	}
	std::cout << "Average compressed rate : " << rate/d.getFiles().size() << std::endl;
	
	// compute average compressed rate for videos 
	rate = 0.0;
	for (auto f : d.getFiles()) {
		if (typeid(*f)==typeid(Video)) {
		 	rate += static_cast<double>(f->getCompressedSize())/f->getSize();
		}
	}
	std::cout << "Average compressed rate for videos : " << rate/d.getFiles().size() << std::endl;
	
	delete v2;
	return 0;
}
