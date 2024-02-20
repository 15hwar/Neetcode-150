//
// Created by Ishwar Patel on 21/02/24.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to calculate the maximum area of water that can be trapped
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        // Iterate until the two pointers meet
        while (left < right) {
            // Calculate the area between the two lines
            int area = min(height[left], height[right]) * (right - left);

            // Update the maximum area encountered so far
            maxArea = max(area, maxArea);

            // Move the pointer pointing to the smaller line inward
            // This is because moving the pointer pointing to the larger line inward will not increase the area,
            // and there might be a larger area with the next line on the other side
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

/*
Intuition:
- The goal is to find the maximum area of water that can be trapped between vertical lines.
- We use a two-pointer approach where we start with the leftmost and rightmost lines.
- By moving the pointers inward while keeping the line with greater height, we maximize the area.

Approach:
1. Initialize two pointers, one at the left end and the other at the right end of the array.
2. Calculate the area between the lines represented by the pointers.
3. Update the maximum area encountered so far.
4. Move the pointer pointing to the smaller line inward, as there might be a larger area with the next line on the other side.
5. Repeat steps 2-4 until the two pointers meet.

Time Complexity:
- The time complexity of this solution is O(n), where n is the number of elements in the height vector.
- This is because we only need to iterate through the array once with two pointers.

Space Complexity:
- The space complexity of this solution is O(1) since it only uses a constant amount of extra space for variables.
*/
