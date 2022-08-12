#ifndef __PRINTER_H__
#define __PRINTER_H__

#include "Printer.h"
#include <iostream>
#include <cstring>

void Printer::SetString(const char* str) {
	strcpy(printer,str);
}
void Printer::ShowString() {
	std::cout << printer << std::endl;
}
#endif // !__PRINTER_H__


