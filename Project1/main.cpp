#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

int err = 0x0;
char mass[3][3] = {
    {'+', '+', '+'},
    {'+', '+', '+'},
    {'+', '+', '+'}
};

bool isGame;
char turn;

int render(char mass[3][3]) { // Изменено на двумерный массив
    for (int i = 0; i < 3; i++) { // Изменено на i < 3
        for (int j = 0; j < 3; j++) { // Изменено на j < 3
            cout << mass[i][j]; // Изменено на mass[i][j] для доступа к элементам
        }
        cout << endl; // Переход на новую строку после завершения внутреннего цикла
    }
    return 0;
}

void changeTurn(char totalTurn) {
    if (totalTurn == 'X') {
        turn = '0';
    }
    else {
        turn = 'X';
    }
}
bool isTileEmpty(int x, int y) {
    if (mass[x][y] == '+') {
        return true;
    }
    else {
        return false;
    }
}

bool isAllTilesNotEmpty() {
    for (int i = 0; i < 3; i++) { // Изменено на i < 3
        for (int j = 0; j < 3; j++) { // Изменено на j < 3
            if (isTileEmpty(i, j)) {
                return false;
            }
        }
    }
    return true;
}


int changeTile(int x, int y, char turn) {
    mass[x][y] = turn;
    return 0;
}



char checkWhoWin(char mass[3][3], char turn) {
    if ((mass[0][0] == turn && mass[0][1] == turn && mass[0][2] == turn) ||
        (mass[1][0] == turn && mass[1][1] == turn && mass[1][2] == turn) ||
        (mass[2][0] == turn && mass[2][1] == turn && mass[2][2] == turn) ||
        (mass[0][0] == turn && mass[1][0] == turn && mass[2][0] == turn) ||
        (mass[0][1] == turn && mass[1][1] == turn && mass[2][1] == turn) ||
        (mass[0][2] == turn && mass[1][2] == turn && mass[2][2] == turn) ||
        (mass[0][0] == turn && mass[1][1] == turn && mass[2][2] == turn) ||
        (mass[0][2] == turn && mass[1][1] == turn && mass[2][0] == turn)) {
        isGame = false;
        cout << turn << " won" << endl;
        return turn;
    }
    else if (isAllTilesNotEmpty()) {
        isGame = false;
        cout << "draw" << endl;
        return '+';
    }
}



int main() {
    isGame = true;
    turn = 'X';

    while (isGame) {
        render(mass);
        int row;
        int column;
        cout << "Enter the row to insert X: ";
        cin >> row;
        cout << "Enter the column to insert X: ";
        cin >> column;

        if (!isTileEmpty(row - 1, column - 1)) {
            cout << "This tile isn't empty" << endl;
            continue;
        }

        changeTile(row - 1, column - 1, turn);

        checkWhoWin(mass, turn);

        changeTurn(turn);
    }
    render(mass);
    return err;
}