// Arkadiusz Œwierczek

#include "Device.h"
device::device(int id) :ComSubject(id) {}
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
void device::addFunction( int i, std::string nazwa)
{
	FunctionDevice a;
	a.SetName(nazwa);
	functions[i]=a;
}
void device::addFunction(std::string nazwa)
{
	int size = functions.size();
	FunctionDevice a;
	a.SetName(nazwa);
	functions[size] = a;
}
void device::deleteFunction(int i)
{
	std::map<int,FunctionDevice>::iterator iterator;
	iterator = functions.find(i);
	if (iterator->first!=0)
		functions.erase(iterator);
}
void device::deleteFunction(std::string nazwa)
{
	std::map<int, FunctionDevice>::iterator iterator;
	for (iterator = functions.begin(); iterator != functions.end(); ++iterator)
	{
		if (iterator->second.GetName() == nazwa)
		{
			functions.erase(iterator);
			return;
		}
	}
}
std::string device::showFunctions()
{
	std::string lista;
	std::map<int, FunctionDevice>::iterator iterator;
	if (functions.empty()) return "No functions added\n";
	for (iterator = functions.begin(); iterator != functions.end(); ++iterator)
	{
		lista += std::to_string(iterator->first);
		lista += '\t';
		lista += iterator->second.GetName();
		lista += '\n';
	}
	return lista;
}
std::map<int, FunctionDevice> *device::showFunctions2()
{
	if (functions.empty()) return nullptr;
	return &functions;
}
