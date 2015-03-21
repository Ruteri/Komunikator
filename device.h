#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "ComSubject.h"


class device : public ComSubject{
private:
	bool active;
	std::map<int, std::string> functions;
	std::map<int, std::string>::iterator iterator;
	std::vector <std::string> history;


public:
	device();
	device(bool);
	~device();
	bool isActive();
	void activate();
	void deActivate();
	std::string showFunctions();
	std::map<int, std::string> *showFunctions2();
	void addFunction(int, std::string);
	void addFunction(std::string);
	void deleteFunction(int);
	void deleteFunction(std::string);
	std::string showLastOperations();
	std::vector<std::string> *showLastOperations2();
};
#endif /* defined(__KomunikatorV2__Device__) */
