#ifndef FIELD_H
#define FIELD_H

#include "base.h"
#include "enum.h"

using namespace std;

class field :public base {
	bool occupied;
public:
	field();
	void set_color(color);
	color get_color();
	void set_occupied(bool);
	bool get_occupied();
};


#endif // !FIELD_H
