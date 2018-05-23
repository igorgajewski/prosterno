#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>

#include "functions.h"
#include "base.h"
#include "player.h"
#include "field.h"

using namespace std;

int main() {
	srand(time(0));
	SetConsoleTitle(TEXT("PROSTERNO"));
	SetConsoleCursorInfo(hConsoleOutput, &param);
	int option;


	
	while (true) {
		option = print("files/mainmenu.txt");
		switch (option) {
		case 4: {
			system("cls");

			// TWORZENIE GRACZY
			string username;
			cout << "Podaj nazwe uzytkownika: ";
			cin >> username;
			int n = rand() % 2;
			color c;
			if (n == 0) c = white; else c = black;
			player p1(username, c);

			username = "komputer";
			if (n == 1) c = white; else c = black;
			player p2(username, c);

			// TWORZENIE PLANSZY

			field** board = new field*[8];
			for (int i = 0; i < 8; i++) {
				board[i] = new field[9];
			}
			setBoard(board);
			drawBoard(board, p1, p2);
			// TODO move
			//if (p2.get_color() == white) { //pierwszy rusza komputer, bo ma biale pionki; dalej leci normalnie gracz->komputer->gracz itd
			//	compMove(board, p2);
			//}
			while (true) {
				userMove(board, p1);
				drawBoard(board, p1, p2);
			}
			// TODO reszta ruchow
			for (int i = 0; i < 8; i++) {
				delete [] board[i];
			}
			delete [] board;
			exit(0); }
		case 5: {
			system("cls");
			option = print("files/rules.txt");
			switch (option) {
			case 5:
				continue;
			case 6:
				exit(0);
			}
			break; }
		case 6:
			exit(0);
		}
	}
}