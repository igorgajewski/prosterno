#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "base.h"
#include "enum.h"
#include "player.h"
#include "field.h"

using namespace std;

extern HANDLE hConsoleOutput;
extern CONSOLE_CURSOR_INFO param;

void setCursor(int, int);
int print(string);
void drawScore(player, player);
void setBoard(field**);
void drawBoard(field**, player, player);
void compMove(field**, player);
void markField(field**, int, int, int, int);
void userMove(field**, player);

#endif // !FUNCTIONS_H