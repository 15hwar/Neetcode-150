//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector> // Include necessary header files

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedRows[9][9] = {0}, usedCols[9][9] = {0}, usedSubgrids[9][9] = {0}; // Arrays to track used numbers in rows, columns, and subgrids

        // Traverse the Sudoku board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { // If the cell is not empty
                    int num = board[i][j] - '0' - 1; // Convert character to integer
                    int index = (i / 3) * 3 + j / 3; // Calculate subgrid index

                    // Check if the number is already used in the current row, column, or subgrid
                    if (usedRows[i][num] || usedCols[j][num] || usedSubgrids[index][num])
                        return false; // If the number is already used, the Sudoku is invalid

                    // Mark the number as used in the corresponding row, column, and subgrid
                    usedRows[i][num] = usedCols[j][num] = usedSubgrids[index][num] = 1;
                }
            }
        }
        return true; // If the Sudoku is valid, return true
    }
};

// Intuition:
// In a valid Sudoku, each row, each column, and each of the 9 subgrids must contain the digits 1-9 without repetition.

// Approach:
// - We iterate through each cell of the Sudoku board.
// - For each non-empty cell, we determine the number and its corresponding row, column, and subgrid.
// - We use arrays to keep track of the usage of numbers in rows, columns, and subgrids.
// - If we find that the number is already used in the current row, column, or subgrid, we return false, indicating an invalid Sudoku.
// - If we traverse the entire board without finding any conflicts, we return true, indicating a valid Sudoku.

// Time Complexity:
// The time complexity of this solution is O(1) because the size of the Sudoku board is fixed (9x9).

// Space Complexity:
// The space complexity is O(1) as well, as we use fixed-size arrays to track the usage of numbers.
