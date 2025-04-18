#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << endl;
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                return true;
            }
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin() {
        // Rows and Columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
                return true;
        }
        // Diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
            return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    char getCurrentPlayer() {
        return this->currentPlayer; // using this pointer
    }

    ~TicTacToe() {
        cout << "\nDestructor called. Game Over!" << endl;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    while (true) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (!game.makeMove(row, col)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (game.checkWin()) {
            game.displayBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            break;
        }

        if (game.checkDraw()) {
            game.displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        game.switchPlayer();
    }

    return 0;
}

