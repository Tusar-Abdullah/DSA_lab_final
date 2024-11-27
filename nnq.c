#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int board[MAX][MAX]; // 2D array to represent the chessboard
int totalSolutions = 0; // Count of all solutions

// Function to print the board
void printBoard(int n) {
    totalSolutions++;
    printf("\nSolution #%d:\n", totalSolutions);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 1) {
                printf("Q "); // Queen
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }
}

// Check if it's safe to place a queen at board[row][col]
int isSafe(int row, int col, int n) {
    // Check the same column
    for (int i = 1; i < row; i++) {
        if (board[i][col] == 1) {
            return 0; // Not safe
        }
    }

    // Check the upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--) {
        if (board[i][j] == 1) {
            return 0; // Not safe
        }
    }

    // Check the upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 1 && j <= n; i--, j++) {
        if (board[i][j] == 1) {
            return 0; // Not safe
        }
    }

    return 1; // Safe to place
}

// Recursive function to solve the N-Queens problem
void solve(int row, int n) {
    if (row > n) { // Base case: All queens are placed
        printBoard(n); // Print the current solution
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col, n)) { // Check if it's safe to place a queen
            board[row][col] = 1;  // Place the queen
            solve(row + 1, n);    // Solve for the next row
            board[row][col] = 0;  // Backtrack: Remove the queen
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    // Initialize the board with 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = 0;
        }
    }

    solve(1, n); // Start solving from the first row

    printf("\nTotal solutions: %d\n", totalSolutions);
    return 0;
}

