#include <iostream>
#include <stdio.h>
#include "CoutWrapper.h"

unsigned long CoutWrapper::write(const char *str){
	return printf("%.*s", 32, str);
}
unsigned long CoutWrapper::write(int value){
	std::cout << value;
	return 1;
}