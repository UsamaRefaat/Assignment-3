
#include <iostream>
#include"include/BoardGame_Classes.hpp"
#include "TicTac5x5.h"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Tic Tac Toe Game. :)\n";
    cout << "please choose one of the following choices:\n";
    cout<<"1-Play with computer"<<endl<<"2-Play with another player\n"<<"->";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new Tic5x5(), players);
    x_o_game.run();
}
