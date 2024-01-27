#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
const int ROW = 3;
const int COL = 3;
const int EMPTY = 0;
int board[ROW][COL];
void inmanhinh() {
    system("cls");
    cout << "--PUZZLE--\n";
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (board[i][j] == EMPTY) {
                cout << "  | ";//vi tri cua o trong
            }
            else {
                cout << board[i][j] << " | ";
            }
        }
        cout << endl;
    }
}
//cac so trong bang
void Board() {
    int num = 1;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            board[i][j] = num++;
        }
    }
    board[ROW - 1][COL - 1] = EMPTY;
}
//cac buoc di chuyen
bool dichuyen(char direction) {
    int emptyRow, emptyCol;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (board[i][j] == EMPTY) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
    }
    int newRow = emptyRow;
    int newCol = emptyCol;
    switch (direction) {
    case 'w':
        newRow = emptyRow - 1;
        break;
    case 'a':
        newCol = emptyCol - 1;
        break;
    case 's':
        newRow = emptyRow + 1;
        break;
    case 'd':
        newCol = emptyCol + 1;
        break;
    default:
        return false;
    }
    if (newRow < 0 and newRow >= ROW and newCol < 0 and newCol >= COL) {
        return false;
    }
    swap(board[emptyRow][emptyCol], board[newRow][newCol]);
    return true;
}
//kiem tra tro choi da ok chua
bool kiemtra() {
    int num = 1;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (board[i][j] != num and !(i == ROW - 1 and j == COL - 1 && board[i][j] == EMPTY)) {
                return false;
            }
            ++num;
        }
    }
    return true;
}
//tron sao cac so
void tron() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; ++i) {
        char randomMove = "wasd"[rand() % 4];
        dichuyen(randomMove);
    }
}
int main() {
    Board();
    tron();
    char userInput;
    do {
        inmanhinh();
        cout << "wasd di chuyen , R choi lai, Q thoat: ";
        userInput = _getch();
        if ( userInput == 'r') {
            tron();
        }
        else if (dichuyen(userInput)) {
            if (kiemtra()) {
                inmanhinh();
                cout << "chuc mung ban da giai xong cau do" << endl;
                break;
            }
        }
    } while ( userInput != 'q');
}
