//
// Created by Ishwar Patel on 06/03/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    // Function to search for a target element in a sorted matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix

        // Binary search to find the row where the target might be located
        int left = 0; // Left pointer
        int right = m - 1; // Right pointer
        int mid; // Mid pointer

        while(left <= right) {
            mid = left + (right - left) / 2; // Calculate mid index

            // Check if target falls within the range of the current row
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1])
                break; // If yes, break the loop
            else if(target < matrix[mid][0]) // If target is smaller than the first element of the current row, search in the upper half
                right = mid - 1;
            else // If target is larger than the last element of the current row, search in the lower half
                left = mid + 1;
        }

        left = 0; // Reset left pointer for binary search in the found row
        right = n - 1; // Reset right pointer for binary search in the found row

        // Binary search to find the target element in the found row
        while(left <= right) {
            int midCol = left + (right - left) / 2; // Calculate mid column index

            if(matrix[mid][midCol] == target) // If target found at midCol in the found row, return true
                return true;
            else if(matrix[mid][midCol] > target) // If target is smaller than the element at midCol, search in the left half
                right = midCol - 1;
            else // If target is larger than the element at midCol, search in the right half
                left = midCol + 1;
        }

        return false; // Target not found
    }

    // Intuition: We want to search for a target element in a sorted matrix.

    // Approach: We use binary search to find the row where the target might be located.
    // Once we find the row, we use binary search again to search for the target element within that row.

    // Time Complexity: O(log(m) + log(n)), where m is the number of rows and n is the number of columns in the matrix.
    //                  Binary search is performed twice, first to find the row and then to find the target element within that row.

    // Space Complexity: O(1), constant space is used.
};
