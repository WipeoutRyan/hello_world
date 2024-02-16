#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // Check for draw
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return ' ';
        }
    }
    return 'D'; // Draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    cout << "Welcome to Tic Tac Toe!\n";

    // Game loop
    while (winner == ' ') {
        cout << "Current board:\n";
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for winner
        winner = checkWinner(board);

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Game over
    cout << "Game over!\n";
    printBoard(board);
    if (winner == 'D')
        cout << "It's a draw!\n";
    else
        cout << "Player " << winner << " wins!\n";

    return 0;
}
