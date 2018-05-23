#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "base.h"
#include "enum.h"

using namespace std;

class player :public base {
	string name;
	int pawns;
public:
	player(string, color);

	string get_name();
	color get_color();
	void set_color(color);
	int get_pawns();
	void remove_pawn();
};

#endif // !PLAYER_H
