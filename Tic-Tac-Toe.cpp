#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);

int main() {
    char board[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}}; // Initial board
    int choice;
    char player = 'X'; // Player 1 starts with 'X'
    bool gameRunning = true;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (gameRunning) {
        displayBoard(board);

        // Player makes a move
        cout << "Player " << player << ", enter the number of the cell: ";
        cin >> choice;

        // Convert choice to board coordinates
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Validate move
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update board
        board[row][col] = player;

        // Check for a win
        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!" << endl;
            gameRunning = false;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameRunning = false;
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    cout << "Game Over!" << endl;
    return 0;
}

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))   // Column
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Diagonal 1
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))   // Diagonal 2
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false; // Empty cell found
        }
    }
    return true; // No empty cells, it's a draw
}
