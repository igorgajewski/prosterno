#include "field.h"

using namespace std;

field::field() :base() { occupied = false; };
void field::set_color(color input) {
	c = input;
}

color field::get_color() {
	return c;
}

void field::set_occupied(bool input) {
	occupied = input;
}

bool field::get_occupied() {
	return occupied;
}