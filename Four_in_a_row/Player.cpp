// Class definition for XO_Player class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"include/connectfour.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Virtual (can change for other player types)
void Player::get_move ( int&x,int& y) {
    cout << "\nPlease enter your move y (0 to 6) : ";
    cin >> y;
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}


connect4Player :: connect4Player(int order, char symbol) : Player(order,symbol) {}

void connect4Player :: get_move(int &x, int &y) {
    cout << "\nPlease enter your move y (0 to 6) separated by spaces: ";
    cin >> y;
}
