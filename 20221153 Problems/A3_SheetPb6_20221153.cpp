// File name: Game of life.
// Purpose: implementation of Game of life game.
// Author(s): Mostafa Mohamed Anwer
// ID(s): 20221153
// Section: S21
// Date: 07/12/2023
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
// please run in Cmd


const int rows = 20;
const int columns = 20;

char grid[rows][columns];
char grid2[rows][columns];

void initialize() {
    int no_alive;
    cout<<"Enter the Number of live cells:";
    cin>>no_alive;
    cout<<"Enter position of live cells(x y) separated by space:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid[i][j] = '.';
            grid2[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < no_alive; ++i) {
        int x,y; cin>>x>>y;
        grid[x][y] = '*';
        grid2[x][y] = grid[x][y];
    }

}

void equal() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid[i][j] = grid2[i][j];
        }
    }
}

void reset() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid[i][j] = '.';
            grid2[i][j] = '.';
        }
    }
}

int count_neighbors(int row,int column) { // function that count no. of neighbors for a cell
    int count{};
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            if ((i == row && j == column) || (i < 0 || j < 0) || (i >= rows || j >= columns)) {
                continue;
            }
            if (grid[i][j] == '*') {
                count++;
            }
        }
    }
    return count;
}

void next_generation() { // generates the next generation
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int cnt = count_neighbors(i,j);
            if (grid[i][j] == '*' && (cnt == 2 || cnt == 3)) {
                grid2[i][j] = '*';
            }else if (grid[i][j] == '.' && cnt == 3) {
                grid2[i][j] = '*';
            }else {
                grid2[i][j] = '.';
            }
        }
    }
    equal();
}

void display() { //Display the grid
    system("cls");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

void run (int no_runs) {
    initialize();
    while (no_runs--) {
        display();
        next_generation();
        usleep(800000);
    }
    cout<<"----The Game has Ended----"<<endl;
    system("pause");
}


int main() {
    cout<<"Enter the Number of runs: ";
    int no_runs;
    cin >> no_runs;
    run(no_runs);
}