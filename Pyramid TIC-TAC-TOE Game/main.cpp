

#include <iostream>
#include"pyramid_X_O.h"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        players[1] = new AIUnbeatablePlayer('o',new pyramid_Board);

    GameManager x_o_game(new pyramid_Board(), players);
    x_o_game.run();
    delete players[0];
    delete players[1];
    system("pause");
}

