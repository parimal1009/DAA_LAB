#include <iostream>
using namespace std;

const int N = 4;
int board[N][N] = {0};

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) if (board[i][j]) return false;
    return true;
}

bool solve(int row) {
    if (row == N) {
        for (int i = 0; i < N; i++, cout << endl)
            for (int j = 0; j < N; j++) cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            foundSolution = solve(row + 1) || foundSolution;
            board[row][col] = 0;
        }
    }
    return foundSolution;
}

int main() {
    if (!solve(0)) cout << "No solution exists.";
    return 0;
}
