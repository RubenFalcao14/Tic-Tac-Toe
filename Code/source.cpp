#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

class Game {
public:

	Game()
	{
		srand(time(0));
		int num = rand() % 6 + 1;

		switch (num)
		{
		case 1:
			cout << "Tip : When starting first place your first X in a corner";
			return;

		case 2:
			cout << "Tip : If your opponent plays the first O in the center, then try to win by placing your second X in the opposite corner from your first";
			return;

		case 3:
			cout << "Tip : If your opponent plays the first O in the center, then try placing your second X on an edge square (not a corner), not touching your first X";
			return;

		case 4:
			cout << "Tip : If your opponent plays their first O in any square besides the center, then your win probability increases";
			return;

		case 5:
			cout << "Tip : Force a draw when the opponent starts in the center, by placing your first X in a corner";
			return;

		case 6:
			cout << "Tip : Force a draw if the opponent starts in the corner, by placing your first X in the center";
			return;

		default:
			cout << "Tip : You are doing great";
			return;
		}
	}

};

class Board : protected Game {
protected:
	char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

public:
	void board()
	{
		system("cls");
		cout << "\n\n\tTic Tac Toe\n\n";

		Game();
		cout << endl << endl;
		cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
		cout << endl;

		cout << "     |     |     " << endl;
		cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

		cout << "     |     |     " << endl << endl;
	}
};

class Player : protected Board {
protected:
	int i = 1;

public:
	void Operation()
	{
		int player = 1, choice;
		i = 0;
		char mark;
		do
		{
			board();
			player = (player % 2) ? 1 : 2;

			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			if (choice == 1 && square[1] == '1')

				square[1] = mark;
			else if (choice == 2 && square[2] == '2')

				square[2] = mark;
			else if (choice == 3 && square[3] == '3')

				square[3] = mark;
			else if (choice == 4 && square[4] == '4')

				square[4] = mark;
			else if (choice == 5 && square[5] == '5')

				square[5] = mark;
			else if (choice == 6 && square[6] == '6')

				square[6] = mark;
			else if (choice == 7 && square[7] == '7')

				square[7] = mark;
			else if (choice == 8 && square[8] == '8')

				square[8] = mark;
			else if (choice == 9 && square[9] == '9')

				square[9] = mark;
			else
			{
				cout << "Invalid move ";

				player--;
				cin.ignore();
				cin.get();
			}
			i = checkwin();

			player++;
		} while (i == -1);
		board();
		if (i == 1)

			cout << "==>\aPlayer " << --player << " win ";
		else
			cout << "==>\aGame draw";

		cin.ignore();
		cin.get();
	}

	int checkwin()
	{
		if (square[1] == square[2] && square[2] == square[3])

			return 1;
		else if (square[4] == square[5] && square[5] == square[6])

			return 1;
		else if (square[7] == square[8] && square[8] == square[9])

			return 1;
		else if (square[1] == square[4] && square[4] == square[7])

			return 1;
		else if (square[2] == square[5] && square[5] == square[8])

			return 1;
		else if (square[3] == square[6] && square[6] == square[9])

			return 1;
		else if (square[1] == square[5] && square[5] == square[9])

			return 1;
		else if (square[3] == square[5] && square[5] == square[7])

			return 1;
		else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
			&& square[4] != '4' && square[5] != '5' && square[6] != '6'
			&& square[7] != '7' && square[8] != '8' && square[9] != '9')

			return 0;
		else
			return -1;
	}

};

int main() {
	Player Op;
	Op.Operation();

	_getch();
}
