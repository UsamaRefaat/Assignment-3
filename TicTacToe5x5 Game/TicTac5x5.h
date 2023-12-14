

#ifndef CLION_PROJECTS_TICTAC5X5_H
#define CLION_PROJECTS_TICTAC5X5_H
#include <bits/stdc++.h>
#include"include/BoardGame_Classes.hpp"
using namespace std;

class Tic5x5 : public Board{
protected:
    int no_X;
    int no_O;
public:
    Tic5x5 ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool check_diag(int r,int c);
    bool check_row(int r,int c);
    bool check_up_down(int r,int c);
    void count_X_O();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};




#endif
