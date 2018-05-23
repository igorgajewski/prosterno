#include <string>
#include "player.h"

using namespace std;

player::player(string s, color input) :base(input) { name = s, c = input, pawns = 9; }

string player::get_name() {
	return name;

}
color player::get_color() {
	return c;
}

void player::set_color(color input) {
	c = input;
}

int player::get_pawns() {
	return pawns;
}

void player::remove_pawn() {
	pawns -= 1;
}