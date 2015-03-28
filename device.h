#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "ComSubject.h"
#include "FunctionDevice.h"


class device : public ComSubject{
private:
    
	bool active;
	std::map<int, FunctionDevice> functions;
	std::vector <std::string> history;


public:
	device(int);
	~device();
	bool isActive();
	void activate();
	void deActivate();
	std::string showFunctions();
	std::map<int, FunctionDevice> *showFunctions2();
	void addFunction(int , std::string );
	void addFunction(std::string);
	void deleteFunction(int);
	void deleteFunction(std::string);
	std::string showLastOperations();
	std::vector<std::string> *showLastOperations2();
}; // zrobic klase funkcji
#endif /* defined(__KomunikatorV2__Device__) */
