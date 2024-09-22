//Tic-Tac-Toe Game 
//Dev-name : Mohamed Ahmed Hamed
// UNI Name : FCAI-Cu-Egypt
//Date : 21 / 9 / 2024
//I am proud of my joining to FCAI Cu and thanks Dr.Mohamed El-Ramly from the heart <3

#include "TicTacToe.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    Table table;  // Create the Table object
    Player player1("Player 1", 'X');  // Create Player 1
    Player player2("Player 2", 'O');  // Create Player 2

    cout << "Welcome to Tic-Tac-Toe Game" << endl;
    cout << "Would you like to start a new Game?" << endl;
    cout << "Enter 1 -> YES and 2 -> NO: ";
    int x;
    cin >> x;

    if (x == 1) {
        while (true) {
            cout << player1.GetName() << " will use " << player1.GetSymbol() << endl;
            cout << player2.GetName() << " will use " << player2.GetSymbol() << endl;

            table.SetTable();  // Set up the initial table
            table.displayTable();  // Display the initial table

            bool gameover = false;
            Player* currentPlayer = &player1;  // Start with player1

            while (!gameover) {
                int cell;
                cout << endl << currentPlayer->GetName() << "'s turn. Enter cell number (1-9): ";
                cin >> cell;

                // Check if the chosen cell is free
                table.UpdateTable(cell, currentPlayer->GetSymbol());

                // Display the updated table
                cout << endl; // Add space before displaying the table
                table.displayTable();
                cout << endl; // Add space after displaying the table

                // Check if the current player has won
                if (table.checkwin()) {
                    cout << endl << currentPlayer->GetName() << " wins!" << endl;
                    currentPlayer->IncreaseScore();
                    gameover = true; // Set gameover to true to end the game
                    break; // Exit the loop
                }
                // Check if the game is a draw
                else if (table.isdraw()) {
                    cout << endl << "It's a draw!" << endl;
                    gameover = true;
                    break; // Exit the loop
                }

                // Switch turns
                currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
            }

            cout << endl; // Add an extra line at the end for better separation


            // Display player information at the end of the game
            player1.DisplayInfo();
            player2.DisplayInfo();
            cout << "Do you wanna play again ? " << endl;
            cout << "Enter 1 -> YES and 2 -> NO: ";
            int w;
            cin >> w;
            if (w != 1) {
                cout << "See you later!";
                return 0;
            }
        }

    }
    else if (x == 2) {
        cout << endl << "See you soon!!" << endl;
    }
    else {
        cout << "Invalid choice :( " << endl << "Game CRASHHHHHHHHHH!!!";
    }

    return 0;
}
