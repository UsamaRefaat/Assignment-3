#include <bits/stdc++.h>
#include "AllGames.h"
using namespace std;

//----------------------------------------TicTacToe5x5 Game-------------------------------------
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

Tic5x5_player ::Tic5x5_player(int order, char symbol) : Player(order,symbol) {}
void Tic5x5_player ::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

//----------------------------------------Connect4 Game-------------------------------------
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
bool Connect4board::update_board( int x, int y, char mark) {
    // Only update if move is valid
    if (!( y < 0 || y >= n_cols)) {
        // Find the lowest empty position in the column
        for (int i = n_rows - 1; i >= 0; i--) {
            if (board[i][y] == ' ') {
                board[i][y] = toupper(mark);  // marking ;
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

connect4Player :: connect4Player(int order, char symbol) : Player(order,symbol) {}

void connect4Player :: get_move(int &x, int &y) {
    cout << "\nPlease enter your move y (0 to 6) separated by spaces: ";
    cin >> y;
}

//----------------------------------------pyramid_X_O Game-------------------------------------
// Set the board
pyramid_Board::pyramid_Board () {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool pyramid_Board::is_valid_move(int row , int col )  {
    if (row<0 || row>2 || col<0 || col>4)
    {return false ;}
    if ((row == 0 && (col == 0 || col == 1 || col == 3||col==4)) ||
        (row == 1 && (col == 0 || col == 4)))
    {return false ;}
    if (board[row][col] != 0) {
        return false;
    }
    return true ;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool pyramid_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (is_valid_move(x,y)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}



// Display the board and the pieces on it
void pyramid_Board::display_board() {
    cout << setw(4) << " ";
    for (int j = 0; j < 5; ++j) {
        cout << setw(4) << (j);
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        cout << setw(4) << i ;
        for (int j = 0; j < 5; ++j) {
            if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                   (i == 1 && (j == 0 || j == 4)) ) ) &&board[i][j] == '\0' ) {
                cout << setw(4) << ".";
            } else {
                cout << setw(4) << board[i][j];
            }
        }
        cout << endl;

    }
    cout<<"\n---------------------------------------------------\n";
}


// Returns true if there is any winner
bool pyramid_Board::is_winner() {
    // Check row wins
    if ((board[1][1] ==  board[1][2]  && board[1][2] == board[1][3]) && board[1][1]!=0) {
        return true;

    }

    if ((board[2][0] ==  board[2][1]  && board[2][1] == board[2][2]) && board[2][0]!=0 ) {
        return true;
    }

    if ((board[2][1] ==  board[2][2]  && board[2][2]==board[2][3]) && board[2][1]!=0  ) {
        return true;
    }

    if ((board[2][2] ==  board[2][3]  && board[2][3] == board[2][4]) && board[2][2]!=0 ) {
        return true;
    }

    // Check column win
    if ((board[0][2]  ==  board[1][2]  && board[1][2]  ==  board[2][2]) &&board[0][2]!=0 ) {
        return true;
    }

    // Check diagonal wins
    if ((board[0][2]  ==  board[1][1]  &&  board[1][1]  ==  board[2][0]) && board[0][2]!=0 ) {
        return true;
    }

    if ((board[0][2]  ==  board[1][3]  && board[1][3]  ==  board[2][4]) && board[0][2]!=0 ) {
        return true;
    }
    return false ;
}

// Return true if 9 moves are done and no winner
bool pyramid_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool pyramid_Board::game_is_over () {
    return n_moves >= 9;
}

pyramid_player ::pyramid_player(int order, char symbol) : Player(order,symbol) {}
void pyramid_player ::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y separated by spaces: ";
    cin >> x >> y;
}



