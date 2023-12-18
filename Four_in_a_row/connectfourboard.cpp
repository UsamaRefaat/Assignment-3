// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "include/connectfour.hpp"
using namespace std;

Connect4board::Connect4board() {
    n_rows = 6 ;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];                 // initialization ;
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Connect4board::update_board( int x,int y, char sy) {
    // Only update if move is valid
    if (!( y < 0 || y >= n_cols)) {
        // Find the lowest empty position in the column
        for (int i = n_rows - 1; i >= 0; i--) {
            if (board[i][y] == ' ') {
                board[i][y] = toupper(sy);  // marking ;
                n_moves++;
                return true;
            }
        }
    }
    return false;
}

// Display the board and the pieces on it
void Connect4board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << setw(2)<< board [i][j] << " |";
        }
        cout << "\n------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Connect4board::is_winner() {
    // Check for a win in rows
    for (int i = 0; i < n_rows ; i++) {
        for (int j = 0; j <= n_cols - 4; j++) {   // last colum i can check it with index 3 ;
            if (board[i][j] != ' ' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check for a win in columns
    for (int i = 0; i <= n_rows - 4; i++) {
        for (int j = 0; j < n_cols; j++) {    // last row i can check it with index 2 ;
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check for a win in diagonals (both directions)
    for (int i = 0; i <= n_rows - 4; i++) {
        for (int j = 0; j <= n_cols - 4; j++) {
            // Check diagonally from top-left to bottom-right
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }

            // Check diagonally from top-right to bottom-left
            if (board[i][j + 3] != ' ' &&
                board[i][j + 3] == board[i + 1][j + 2] &&
                board[i][j + 3] == board[i + 2][j + 1] &&
                board[i][j + 3] == board[i + 3][j]) {
                return true;
            }
        }
    }

    return false;
}

// Return true if 42 moves are done and no winner
bool Connect4board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Connect4board::game_is_over () {
    return n_moves >= 42;
}

