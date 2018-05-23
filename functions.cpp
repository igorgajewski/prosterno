#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include "functions.h"

using namespace std;

HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); // GLOBALNE, BO I TAK Z JEDNEGO KORZYSTAM
CONSOLE_CURSOR_INFO param = { 100, false };

void setCursor(int x, int y) { // USTALENIE POZYCJI KURSORA W KONSOLI
	COORD Cursor_Pos = { x, y };
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

int print(string s) { // OBSLUGA PLIKOW - WYPISANIE NA EKRAN ZAWARTOSCI
	ifstream menu(s);
	string title;
	char c;
	int x, y;
	system("cls");
	SetConsoleTextAttribute(hConsoleOutput, 10);
	if (menu.is_open()) {
		while (getline(menu, title)) {
			cout << title << endl;
		}
		menu.close();
	}
	else {
		cout << "Unable to open";
		exit(1);
	}

	if (s == "files/mainmenu.txt") {
		x = 1, y = 4;
		setCursor(x, y);
		cout << "X";
		while ((c = _getch()) != 13) {
			if (c == 's') {
				setCursor(x, y);
				cout << " ";
				y++;
				if (y > 6)
					y = 6;
				setCursor(x, y);
				cout << "X";
				
			}
			else if (c == 'w') {
				setCursor(x, y);
				cout << " ";
				y--;
				if (y < 4)
					y = 4;
				setCursor(x, y);
				cout << "X";
				
			}
		}
	}
	else if (s == "files/rules.txt") {
		x = 1, y = 5;
		setCursor(x, y);
		cout << "X";
		while ((c = _getch()) != 13) {
			if (c == 's') {
				setCursor(x, y);
				cout << " ";
				y++;
				if (y > 6)
					y = 6;
				setCursor(x, y);
				cout << "X";
			}
			else if (c == 'w') {
				setCursor(x, y);
				cout << " ";
				y--;
				if (y < 5)
					y = 5;
				setCursor(x, y);
				cout << "X";
			}
		}
	}
	return y;
}

void drawScore(player p1, player p2) {
	cout << p1.get_name() << " - ";
	if (p1.get_color() == white) cout << "biale";
	else cout << "czarne";
	cout << " - " << p1.get_pawns() << endl;
	cout << p2.get_name() << " - ";
	if (p2.get_color() == white) cout << "biale";
	else cout << "czarne";
	cout << " - " << p2.get_pawns() << endl;
}

void setBoard(field**board) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			if ((i + j) % 2 == 0) {
				board[i][j].set_color(black);
				if (i > 5) {
					board[i][j].set_occupied(true);
				}
			}
			else {
				board[i][j].set_color(white);
				if (i < 2) {
					board[i][j].set_occupied(true);
				}
			}
		}
	}
}

void drawBoard(field** board, player p1, player p2) {
	system("cls");
	SetConsoleTextAttribute(hConsoleOutput, 10);
	drawScore(p1, p2);
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j].get_color() == white) {
				SetConsoleTextAttribute(hConsoleOutput, 112);
				cout.width(2);
				if(board[i][j].get_occupied()==true)
					cout << "O";
				else cout << " ";
			}
			else if (board[i][j].get_color() == black) {
				SetConsoleTextAttribute(hConsoleOutput, 143);
				cout.width(2);
				if (board[i][j].get_occupied() == true)
					cout << "O";
				else cout << " ";
			}
		}
		cout << endl;
	}
}

void compMove(field** board, player p) {
	if (p.get_color() == white) {
		int i = 0, j = 0;
		while (board[i][j].get_occupied() == true && board[i][j].get_color() == black) { // losuje pionek
			i = rand() % 8;
			j = rand() % 9;
		}

	}
}

void markField(field** board, int x, int y, int color1, int color2) { // ZAZNACZENIE POLA, Z KTOREGO CHCEMY ZABRAC PIONEK
	if (board[x][y].get_color() == white) {
		SetConsoleTextAttribute(hConsoleOutput, color1);
		cout.width(2);
		if (board[x][y].get_occupied() == true)
			cout << "O";
		else cout << " ";
	}
	else if (board[x][y].get_color() == black) {
		SetConsoleTextAttribute(hConsoleOutput, color2);
		cout.width(2);
		if (board[x][y].get_occupied() == true)
			cout << "O";
		else cout << " ";
	}
	SetConsoleTextAttribute(hConsoleOutput, 10);
}

void userMove(field** board, player p) {
	int xC = 0, x = 0, yC = 3, y = 0; // xC, yC - do poprawnego wyswietlania w konsoli; x, y - do skakania po tablicy zawierajacej pola field
	char c;
	setCursor(xC, yC);
	markField(board, x, y, 192, 207);
	while (true) {
		while ((c = _getch()) != 13) {
			if (c == 's') {
				setCursor(xC, yC);
				markField(board, x, y, 112, 143);
				x++;
				yC++;
				if (yC > 10) {
					yC = 10;
					x--;
				}
				setCursor(xC, yC);
				markField(board, x, y, 192, 207);
			}
			else if (c == 'w') {
				setCursor(xC, yC);
				markField(board, x, y, 112, 143);
				x--;
				yC--;
				if (yC < 3) {
					yC = 3;
					x++;
				}
				setCursor(xC, yC);
				markField(board, x, y, 192, 207);
			}
			else if (c == 'a') {
				setCursor(xC, yC);
				markField(board, x, y, 112, 143);
				xC -= 2;
				y--;
				if (xC < 0) {
					xC = 0;
					y++;
				}
				setCursor(xC, yC);
				markField(board, x, y, 192, 207);
			}
			else if (c == 'd') {
				setCursor(xC, yC);
				markField(board, x, y, 112, 143);
				xC += 2;
				y++;
				if (xC > 16) {
					xC = 16;
					y--;
				}
				setCursor(xC, yC);
				markField(board, x, y, 192, 207);
			}
		}
		if (p.get_color() == white) {
			if (board[x][y].get_color() == black && board[x][y].get_occupied() == true)
				break;
		}
		else if(p.get_color()==black){
			if (board[x][y].get_color() == white && board[x][y].get_occupied() == true)
				break;
		}
		continue;
	}
	setCursor(xC, yC);
	markField(board, x, y, 32, 47);

	// wybor pola, na ktore chcemy przeniesc pionek
	xC = 0, yC = 3;
	int x2 = 0, y2 = 0;
	setCursor(xC, yC);
	markField(board, x2, y2, 192, 207);
	while (true) {
		while ((c = _getch()) != 13) {
			if (c == 's') {
				setCursor(xC, yC);
				if (x == x2 && y == y2) {
					markField(board, x2, y2, 32, 47);
				}
				else {
					markField(board, x2, y2, 112, 143);
				}
				x2++;
				yC++;
				if (yC > 10) {
					yC = 10;
					x2--;
				}
				setCursor(xC, yC);
				markField(board, x2, y2, 192, 207);
			}
			else if (c == 'w') {
				setCursor(xC, yC);
				if (x == x2 && y == y2) {
					markField(board, x2, y2, 32, 47);
				}
				else {
					markField(board, x2, y2, 112, 143);
				}
				x2--;
				yC--;
				if (yC < 3) {
					yC = 3;
					x2++;
				}
				setCursor(xC, yC);
				markField(board, x2, y2, 192, 207);
			}
			else if (c == 'a') {
				setCursor(xC, yC);
				if (x == x2 && y == y2) {
					markField(board, x2, y2, 32, 47);
				}
				else {
					markField(board, x2, y2, 112, 143);
				}
				xC -= 2;
				y2--;
				if (xC < 0) {
					xC = 0;
					y2++;
				}
				setCursor(xC, yC);
				markField(board, x2, y2, 192, 207);
			}
			else if (c == 'd') {
				setCursor(xC, yC);
				if (x == x2 && y == y2) {
					markField(board, x2, y2, 32, 47);
				}
				else {
					markField(board, x2, y2, 112, 143);
				}
				xC += 2;
				y2++;
				if (xC > 16) {
					xC = 16;
					y2--;
				}
				setCursor(xC, yC);
				markField(board, x2, y2, 192, 207);
			}
		}
		if (p.get_color() == white) {
			if (board[x2][y2].get_color() == black && board[x2][y2].get_occupied() == false) {
				if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) < 1.5) {
					if (x2 < x) {
						break;
					}
					else if (x2==x) {
						continue;
					}
					else {
						if (y2 > y) {
							if (board[x2][y2 + 1].get_occupied() == false)
								continue;
							else {
								//TODO zbijanie pionkow
							}
						}
						else if (y2==y) {
							continue;
						}
						else {
							if (board[x2][y2 - 1].get_occupied() == false)
								continue;
							else {
								//TODO zbijanie pionkow
							}
						}
					}
				}
			}
		}
		else if (p.get_color() == black) {
			if (board[x2][y2].get_color() == white && board[x2][y2].get_occupied() == false) {
				if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) < 1.5) {
					if (x2 > x) {
						break;
					}
					else if(x2==x) {
						continue;
					}
					else {
						if (y2 > y) {
							if (board[x2][y2 + 1].get_occupied() == false)
								continue;
							else {
								//TODO zbijanie pionkow
							}
						}
						else if (y2 == y) {
							continue;
						}
						else {
							if (board[x2][y2 - 1].get_occupied() == false)
								continue;
							else {
								//TODO zbijanie pionkow
							}
						}
					}
				}
			}
		}
		continue;
	}
	board[x][y].set_occupied(false);
	board[x2][y2].set_occupied(true);
}