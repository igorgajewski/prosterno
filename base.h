#ifndef BASE_H
#define BASE_H

#include <string>
#include "enum.h"

using namespace std;

class base {
protected:
	color c;
	base() {};
	base(color input) : c(input) {};
public:
	virtual color get_color() = 0;
	virtual void set_color(color) = 0;
};

#endif // !BASE_H
