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
	friend std::ostream& operator<<(std::ostream& stream, device& dev)
	{
		stream << "ID: " << dev.getID() << "\nStatus:" << dev.isActive() << "\nFunkcje:\n" << dev.showFunctions() << std::endl;
		return stream;
	}
};
#endif /* defined(__KomunikatorV2__Device__) */
