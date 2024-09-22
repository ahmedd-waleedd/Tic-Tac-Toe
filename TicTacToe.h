#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Table {
private:
    vector<vector<char>> mytable;

public:
    Table();                     // Constructor
    void SetTable();             // Method to set the table
    void displayTable();         // Method to display the table
    void ResetBoard();           // Method to reset the board
    void UpdateTable(int x, char symbol); // Method to update the table
    bool checkwin();
    bool isdraw();
};

class Player {
private:
    char Symbol;
    string Name;
    int Score = 0;

public:
    Player(string name , char symbol);
    string GetName();            // Method to get player's name
    char GetSymbol();  // Method to get player's symbol
    int getScore();
    void DisplayInfo();
    void IncreaseScore();
};

#endif // TICTACTOE_H
