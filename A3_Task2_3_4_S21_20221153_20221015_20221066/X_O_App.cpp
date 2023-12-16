#include <bits/stdc++.h>
#include"AllGames.h"

using namespace std;

int main() {
    int Game;
    cout<<"Select the game that you want to play:\n"<<"1-TicTacToe3x3\n2-TicTacToe5x5\n";
    cout<<"3-Pyramid TicTacToe\n4-Four in a row"<<endl<<"-->";
    cin >> Game;
    int choice;
    Player* players[2];
    if (Game == 1) {
        players[0] = new Player (1, 'x');
        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);
        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
    } else if (Game == 2) {
        players[0] = new Tic5x5_player (1, 'x');

        cout << "Welcome to FCAI TicTacToe 5x5 Game. :)\n";
        cout << "please choose one of the following choices:\n";
        cout<<"1-Play with computer"<<endl<<"2-Play with another player\n"<<"->";
        cin >> choice;
        if (choice != 1)
            players[1] = new Tic5x5_player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new Tic5x5(), players);
        x_o_game.run();
    }else if (Game == 3) {
        players[0] = new pyramid_player (1, 'x');

        cout << "Welcome to Pyramid TicTacToe Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new pyramid_player(2, 'o');
        else
            players[1] = new RandomPlayer('o', 5);

        GameManager x_o_game(new pyramid_Board(), players);
        x_o_game.run();
        delete players[0];
        delete players[1];
    } else if (Game == 4) {
        players[0] = new connect4Player (1, 'x');

        cout << "Welcome to FCAI Connect4 Game. :)\n";
        cout << "Press 1 if you want to play with computer  : ";
        cin >> choice;
        if (choice != 1)
            players[1] = new connect4Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 7);

        GameManager x_o_game (new Connect4board() , players);
        x_o_game.run();
    } else {
        cout<<"INVALID CHOICE";
        exit(0);
    }
}
