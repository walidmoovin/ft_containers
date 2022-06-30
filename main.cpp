#include "vector.hpp"
#include <iostream>

template <typename T>
void printVector(const ft::Vector<T>& vector){
	for(size_t i = 0; i < vector.getSize(); i++){
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

int main(void)
{
	ft::Vector<std::string> vect;

	vect.pushBack("olivier");
	vect.pushBack("tg");
	vect.pushBack("stp");
	printVector(vect);
}