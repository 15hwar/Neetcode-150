//
// Created by Ishwar Patel on 03/03/24.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Function to calculate the largest rectangle area formed by the given heights
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // Number of heights
        stack<pair<int, int>> stk; // Stack to store pairs of (index, height)
        int maxArea = 0; // Maximum area of the rectangle

        // Iterate through the heights
        for(int i = 0; i < n; i++) {
            int start = i; // Start index of the rectangle

            // Check if there are any heights in the stack greater than the current height
            while(!stk.empty() && stk.top().second > heights[i]) {
                start = stk.top().first; // Update the start index
                int width = i - start; // Calculate the width of the rectangle
                int height = stk.top().second; // Height of the rectangle
                maxArea = max(maxArea, height * width); // Update the maximum area
                stk.pop(); // Remove the height from the stack
            }

            // Push the current height and start index onto the stack
            stk.push({start, heights[i]});
        }

        // Calculate the area of any remaining rectangles in the stack
        while(!stk.empty()) {
            int height = stk.top().second; // Height of the rectangle
            int width = n - stk.top().first; // Width of the rectangle
            maxArea = max(maxArea, height * width); // Update the maximum area
            stk.pop(); // Remove the height from the stack
        }

        return maxArea; // Return the maximum area
    }

    // Intuition: We want to find the largest rectangle area formed by the given heights.

    // Approach: We use a stack to keep track of increasing heights. For each height, we calculate the area of the rectangle that ends at that height.
    // We iterate through the heights, and for each height, we check if there are any heights in the stack greater than the current height.
    // If there are, we calculate the area of the rectangle formed by the previous heights and update the maximum area.
    // We then push the current height and index onto the stack.
    // After iterating through all heights, we calculate the area of any remaining rectangles in the stack.

    // Time Complexity: O(n), where n is the number of heights. We iterate through the heights once.
    // Space Complexity: O(n), where n is the number of heights (for the stack).
};
