#include "TicTacToe.h"


// Table's methods

// Constructor
Table::Table() : mytable(3, vector<char>(3, '0')) {}

// SetTable method
void Table::SetTable() {
	char num = '1';
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			mytable[i][j] = num;
			num++;
		}
}

// displayTable method
void Table::displayTable() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j != 2) {
				cout << mytable[i][j] << " | ";
			}
			else {
				cout << mytable[i][j];
			}
		}
		if (i < 2) {
			cout << endl << "---------" << endl;
		}
	}
}

// ResetBoard method
void Table::ResetBoard() {
	mytable = vector<vector<char>>(3, vector<char>(3, '0'));
}

// UpdateTable method (to be implemented)
void Table::UpdateTable(int x, char symbol) {
	int row = (x - 1) / 3; // Convert 1-9 to row
	int col = (x - 1) % 3; // Convert 1-9 to column
	while (mytable[row][col] == 'X' || mytable[row][col] == 'O') {
		cout << "Cell already occupied! Choose a different cell: ";
		cin >> x;
		row = (x - 1) / 3;  // Recalculate row based on new input
		col = (x - 1) % 3;  // Recalculate col based on new input
	}
	mytable[row][col] = symbol;
}

//Check win method
bool Table::checkwin() {
	// Check rows
	for (int i = 0; i < 3; i++) {
		if (mytable[i][0] == mytable[i][1] && mytable[i][1] == mytable[i][2] && mytable[i][0] != 0) {
			return true;
		}
	}

	// Check columns
	for (int i = 0; i < 3; i++) {
		if (mytable[0][i] == mytable[1][i] && mytable[1][i] == mytable[2][i] && mytable[0][i] != 0) {
			return true;
		}
	}

	// Check diagonals
	if (mytable[0][0] == mytable[1][1] && mytable[1][1] == mytable[2][2] && mytable[0][0] != 0) {
		return true;
	}
	if (mytable[0][2] == mytable[1][1] && mytable[1][1] == mytable[2][0] && mytable[0][2] != 0) {
		return true;
	}

	return false; // No win 
}

//check draw
bool Table::isdraw() {
	// Check if the board is full
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mytable[i][j] != 'X' && mytable[i][j] != 'O') {
				return false; // There's at least one empty cell
			}
		}
	}

	// If the board is full and no one has won, it's a draw
	return true;
}


// Player's methods 

// SetName method
 Player::Player(string name , char symbol) {
	if (name.empty()) {
		cout << "Name cannot be empty!" << endl;
	}
	else {
		Name = name;
	}
	Symbol = symbol;
}

// GetName method
string Player::GetName() {
	return Name;
}


// GetSymbol method
char Player::GetSymbol() {
	return Symbol;
}

int Player::getScore() {
	return Score;
}

void Player::DisplayInfo() {
	cout << "Player: " << Name << " | Symbol: " << Symbol << " | Score: " << Score << endl;
}

void Player::IncreaseScore() { Score++; }