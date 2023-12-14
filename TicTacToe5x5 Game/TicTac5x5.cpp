
#include "TicTac5x5.h"
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
// Set the board
Tic5x5::Tic5x5 () {
    no_X = no_O = 0;
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Tic5x5::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Tic5x5::display_board() {
    cout << "\n-----------------------------------------------";
    for (int i{}; i < 5; i++) {
        cout << "\n| ";
        for (int j{}; j < 5; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}
//This function checks diagonal for a Winner
bool Tic5x5 ::check_diag(int r,int c) {
    if (r > 2){
        return false;
    }
    if (c > 2) {
        if (board[r][c] == board[r+1][c-1] && board[r+1][c-1] == board[r+2][c-2]) {
            if (board[r][c] == 'X' || board[r][c] == 'O') {
                return true;
            }
        }
    } else {
        if (board[r][c] == board[r+1][c+1] && board[r+1][c+1] == board[r+2][c+2]) {
            if (board[r][c] == 'X' || board[r][c] == 'O') {
                return true;
            }
        }
    }
    return false;
}
//This function checks row for a Winner
bool Tic5x5::check_row(int r, int c) {
    if (c > 2) {
        return false;
    }
    if (board[r][c] == board[r][c+1] && board[r][c+1] == board[r][c+2]) {
        if (board[r][c] == 'X' || board[r][c] == 'O') {
            return true;
        }
    }
    return false;
}
//This Function Checks upward and downward for a winner
bool Tic5x5::check_up_down(int r, int c) {
    if (r <= 2) {
        if (board[r][c] == board[r+1][c] && board[r+1][c] == board[r+2][c]) {
            if (board[r][c] == 'X' || board[r][c] == 'O') {
                return true;
            }
        }
    }
    return false;
}


// calculate no. of successful sequence of X's and O's
void Tic5x5 ::count_X_O() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (check_diag(i,j) || check_row(i,j) || check_up_down(i,j)) {
                if (board[i][j] == 'X') {
                    no_X++; //increment no of successful sequence of X's
                } else {
                    no_O++; //increment no of successful sequence of O's
                }
            }
        }
    }
    return;
}

// calculate no. of successful sequence of X's and O's then check if the first player won or not
bool Tic5x5::is_winner() {
    if (!game_is_over()) {return false;}
    count_X_O();
    if (no_X > no_O) {
        cout<<"X wins";
        exit(0);
    } else if (no_O > no_X) {
        cout<<"O wins";
        exit(0);
    }
    return false;
}

// Checks if no. of successful sequence of X's equals to no. of successful sequence of O's
bool Tic5x5::is_draw() {
    return (no_O == no_X && n_moves == 24);
}
// Checks that 24 square out of 25 are filled
bool Tic5x5::game_is_over () {
    return n_moves == 24;
}