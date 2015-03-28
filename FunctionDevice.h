#ifndef FUNCTIONDEVICE_H
#define FUNCTIONDEVICE_H

#include <string>

class FunctionDevice
{
	std::string name;
public:
	void SetName(std::string);
	std::string GetName();
};

#endif