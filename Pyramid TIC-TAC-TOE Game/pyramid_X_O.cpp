#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "pyramid_X_O.h"
using namespace std;

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
    if (row<0 || row>2 || col <0 || col>4)
    {return false ;}
    if ((row == 0 && (col == 0 || col == 1 || col == 3||col==4)) ||
             (row == 1 && (col == 0 || col == 4)))
    {return false ;}
    if (board[row][col] != '\0') {
        return false;
    }
    return true ;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool pyramid_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (is_valid_move(x,y) && (board[x][y] == 0)) {
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
    memset(possible_wins, 0, sizeof(possible_wins));
    // Check row wins
    if ((board[1][1] ==  board[1][2]  && board[1][2] == board[1][3]) && board[1][1]!=0) {
        possible_wins[0]=1;
        return true;

    }

    if ((board[2][0] ==  board[2][1]  && board[2][1] == board[2][2]) && board[2][0]!=0 ) {
        possible_wins[1]=1;
        return true;
    }

    if ((board[2][1] ==  board[2][2]  && board[2][2]==board[2][3]) && board[2][1]!=0  ) {
        possible_wins[2]=1;
        return true;
    }

    if ((board[2][2] ==  board[2][3]  && board[2][3] == board[2][4]) && board[2][2]!=0 ) {
        possible_wins[3]=1;
        return true;
    }

    // Check column win
    if ((board[0][2]  ==  board[1][2]  && board[1][2]  ==  board[2][2]) &&board[0][2]!=0 ) {
        possible_wins[4]=1;
        return true;
    }

    // Check diagonal wins
    if ((board[0][2]  ==  board[1][1]  &&  board[1][1]  ==  board[2][0]) && board[0][2]!=0 ) {
        possible_wins[5]=1;
        return true;
    }

    if ((board[0][2]  ==  board[1][3]  && board[1][3]  ==  board[2][4]) && board[0][2]!=0 ) {
        possible_wins[6]=1;
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


void pyramid_Board::display_winner()
{
    if (possible_wins[0]){


        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (i == 1 && j >= 1 && j <= 3 && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    else if (possible_wins[1])
    {
        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (i == 2 && j >= 0 && j < 3 && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    else if (possible_wins[2])
    {
        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (i == 2 && j >= 1 && j < 4 && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    else if (possible_wins[3])
    {
        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (i == 2 && j >= 2 && j < 5 && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    else if (possible_wins[4])
    {
        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (j == 2 && i >= 0 && i < 3 && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    else if (possible_wins[5])
    {
        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    else if (possible_wins[6])
    {
        cout << setw(4) << " ";
        for (int j = 0; j < 5; ++j) {
            cout << setw(4) << (j);
        }
        cout << endl;

        for (int i = 0; i < 3; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < 5; ++j) {
                if ((!((i == 0 && (j == 0 || j == 1 || j == 3 || j == 4)) ||
                       (i == 1 && (j == 0 || j == 4)))) && board[i][j] == '\0') {
                    cout << setw(4) << ".";
                } else if (((i == 0 && j == 2) || (i == 1 && j == 3) || (i == 2 && j == 4)) && board[i][j] != '\0') {
                    // Print specific cells in red
                    set_red_text_color();
                    cout << setw(4) << board[i][j];
                    reset_text_color();
                } else {
                    cout << setw(4) << board[i][j];
                }
            }
            cout << endl;
        }

        cout << "\n---------------------------------------------------\n";
    }
    }

