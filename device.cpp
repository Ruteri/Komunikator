// Arkadiusz Œwierczek

#include "Device.h"

device::device()
{
	active = false;
}
device::device(bool i)
{
	active = i;
}
device::~device()
{
	if (!functions.empty())
		functions.clear();
}
bool device::isActive()
{
	return active ? 1 : 0;
}
void device::activate()
{
	active = true;
}
void device::deActivate()
{
	active = false;
}
void device::addFunction(int i, std::string nazwa)
{
	functions[i]=nazwa;
}
void device::addFunction(std::string nazwa)
{
	int size = functions.size();
	functions[size] = nazwa;
}
void device::deleteFunction(int i)
{
	iterator = functions.find(i);
	if (iterator->first!=0)
		functions.erase(iterator);
}
void device::deleteFunction(std::string nazwa)
{
	for (iterator = functions.begin(); iterator != functions.end(); ++iterator)
	{
		if (iterator->second == nazwa)
		{
			functions.erase(iterator);
			return;
		}
	}
}
std::string device::showFunctions()
{
	std::string lista;
	if (functions.empty()) return "No functions added\n";
	for (iterator = functions.begin(); iterator != functions.end(); ++iterator)
	{
		lista += std::to_string(iterator->first);
		lista += '\t';
		lista += iterator->second;
		lista += '\n';
	}
	return lista;
}
std::map<int, std::string> *device::showFunctions2()
{
	if (functions.empty()) return nullptr;
	return &functions;
}
