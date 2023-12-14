#ifndef PYRAMIDTICTACTOE_PYRAMID_X_O_H
#define PYRAMIDTICTACTOE_PYRAMID_X_O_H
#include <bits/stdc++.h>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
    int possible_wins[7] ;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board (int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
    virtual void display_winner()=0;
    virtual bool is_valid_move(int row , int col )=0;

};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class pyramid_Board:public Board {
private:
    void set_red_text_color() {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 12 is the code for red color in Windows
#endif
    }

    void reset_text_color() {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset color in Windows
#endif
    }
public:
    pyramid_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool is_valid_move(int row , int col );
    void display_winner();

};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    RandomPlayer (char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};

class AIUnbeatablePlayer : public Player {
private:
    Board *boardPtr;

    // Function to check if a move leads to a win for a specific player
    bool is_winning_move(int row, int col, char playerSymbol) {
        boardPtr->update_board(row, col, playerSymbol);
        bool isWinning = boardPtr->is_winner();
        boardPtr->update_board(row, col, 0);  // Undo the simulated move
        return isWinning;
    }

public:
    AIUnbeatablePlayer(char symbol, pyramid_Board *boardPtr) : Player(symbol), boardPtr(boardPtr) {
        this->name = "Unbeatable AI Player";
    }

    void get_move(int &x, int &y) override {
        // Check for opponent's winning moves and block them
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (boardPtr->is_valid_move(i, j)) {
                    boardPtr->update_board(i, j, (symbol == 'x') ? 'o' : 'x');

                    // Check if the opponent's move leads to a win
                    if (boardPtr->is_winner()) {
                        x = i;
                        y = j;
                        boardPtr->update_board(i, j, 0);  // Undo the simulated move
                        return;
                    }

                    // Undo the simulated move
                    boardPtr->update_board(i, j, 0);
                }
            }
        }

        // Check for winning moves for the AI player
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (boardPtr->is_valid_move(i, j)) {
                    boardPtr->update_board(i, j, symbol);

                    // Check if the move leads to a win for the AI player
                    if (boardPtr->is_winner()) {
                        x = i;
                        y = j;
                        boardPtr->update_board(i, j, 0);  // Undo the simulated move
                        return;
                    }

                    // Undo the simulated move
                    boardPtr->update_board(i, j, 0);
                }
            }
        }

        // If no winning move or blocking move, make a strategic move
        // This version considers blocking the opponent's potential winning moves more thoroughly
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (boardPtr->is_valid_move(i, j)) {
                    // Simulate the AI's move
                    boardPtr->update_board(i, j, symbol);

                    // Check if this move blocks the opponent's potential winning moves
                    bool blocksOpponentWinningMoves = false;
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 5; ++n) {
                            if (boardPtr->is_valid_move(m, n)) {
                                boardPtr->update_board(m, n, (symbol == 'x') ? 'o' : 'x');
                                if (boardPtr->is_winner()) {
                                    blocksOpponentWinningMoves = true;
                                }
                                boardPtr->update_board(m, n, 0);
                            }
                        }
                        if (blocksOpponentWinningMoves) {
                            break;
                        }
                    }

                    // Undo the simulated move
                    boardPtr->update_board(i, j, 0);

                    // If the move blocks the opponent's potential winning moves, choose it
                    if (blocksOpponentWinningMoves) {
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
        }

        // If no winning move, blocking move, make a random move
        x = rand() % 3;
        y = rand() % 5;

        // Keep generating random moves until a valid move is found
        while (!boardPtr->is_valid_move(x, y) || !boardPtr->update_board(x, y, symbol)) {
            x = rand() % 3;
            y = rand() % 5;
        }
    }


};





///////////////////////////////////////////
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};


#endif //PYRAMIDTICTACTOE_PYRAMID_X_O_H
