import java.util.*;

public class NQueens {

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        char[][] board = new char[n][n];

        // Initialize board with '.'
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        solve(0, board, result, n);
        return result;
    }

    private void solve(int row, char[][] board, List<List<String>> result, int n) {
        // Base case: All queens placed
        if (row == n) {
            result.add(construct(board));
            return;
        }

        // Try placing queen in each column of current row
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, result, n);
                board[row][col] = '.';  // Backtrack
            }
        }
    }

    private boolean isSafe(int row, int col, char[][] board, int n) {
        // Check column (upward)
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    private List<String> construct(char[][] board) {
        List<String> res = new ArrayList<>();
        for (char[] row : board) {
            res.add(new String(row));
        }
        return res;
    }

    public static void main(String[] args) {
        NQueens nq = new NQueens();

        int n = 4;
        List<List<String>> solutions = nq.solveNQueens(n);

        System.out.println("N-Queens Solutions for n = " + n + ":");
        System.out.println("Total solutions: " + solutions.size());

        for (int i = 0; i < solutions.size(); i++) {
            System.out.println("\nSolution " + (i + 1) + ":");
            for (String row : solutions.get(i)) {
                System.out.println(row);
            }
        }
    }
}

/*
 * N-Queens Problem (Backtracking)
 *
 * Problem: Place N queens on an NxN chessboard such that no two queens attack each other.
 *
 * Approach:
 * 1. Place queens row by row
 * 2. For each row, try all columns
 * 3. Check if position is safe (no queen in same column or diagonals)
 * 4. If safe, place queen and recurse to next row
 * 5. If not safe or no solution found, backtrack
 *
 * Time Complexity: O(N!)
 * Space Complexity: O(N^2) for the board
 */
