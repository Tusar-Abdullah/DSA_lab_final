#include<bits/stdc++.h>
using namespace std;

int board[10][10];
int totalSolutions = 0;

void printBoard(int n) {
    totalSolutions++;
    cout << "Solution #" << totalSolutions << ":\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int isSafe(int row, int col, int n) {

    for (int i = 1; i < row; i++) {
        if (board[i][col] == 1) return 0;
    }


    for (int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--) {
        if (board[i][j] == 1) return 0;
    }


    for (int i = row - 1, j = col + 1; i >= 1 && j <= n; i--, j++) {
        if (board[i][j] == 1) return 0;
    }

    return 1;
}

void solve(int row, int n) {
    if (row > n) {
        printBoard(n);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            solve(row + 1, n);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;

    solve(1, n);
    cout << "Total Solutions: " << totalSolutions << endl;

    return 0;
}

