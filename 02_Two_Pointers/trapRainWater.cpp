//
// Created by Ishwar Patel on 21/02/24.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to calculate the total trapped water between the bars
    int trap(vector<int>& height) {
        int n = height.size();
        int trappedWater = 0;
        int leftMax = height[0], rightMax = height[n - 1];
        int left = 0, right = n - 1;

        // Iterate until the two pointers meet
        while (left < right) {
            // If the height of left bar is less than or equal to the height of right bar
            if (height[left] <= height[right]) {
                left++;
                // Update left max
                leftMax = max(leftMax, height[left]);
                // Add trapped water based on left max and current height
                trappedWater += leftMax - height[left];
            } else {
                right--;
                // Update right max
                rightMax = max(rightMax, height[right]);
                // Add trapped water based on right max and current height
                trappedWater += rightMax - height[right];
            }
        }

        return trappedWater;
    }
};

/*
Intuition:
- The goal is to calculate the total trapped water between the bars represented by the array.
- We use a two-pointer approach where we start with the leftmost and rightmost bars.
- We calculate the trapped water by considering the minimum height of bars on both sides at each step.

Approach:
1. Initialize two pointers, one at the left end and the other at the right end of the array.
2. Initialize variables to track the maximum height of bars encountered from left and right directions.
3. Iterate until the two pointers meet.
4. If the height of the left bar is less than or equal to the height of the right bar:
   - Move the left pointer to the right.
   - Update the left max height encountered so far.
   - Add trapped water based on the left max and current height.
5. If the height of the right bar is less than the height of the left bar:
   - Move the right pointer to the left.
   - Update the right max height encountered so far.
   - Add trapped water based on the right max and current height.
6. Repeat steps 3-5 until the two pointers meet.

Time Complexity:
- The time complexity of this solution is O(n), where n is the number of elements in the height vector.
- This is because we only need to iterate through the array once with two pointers.

Space Complexity:
- The space complexity of this solution is O(1) since it only uses a constant amount of extra space for variables.
*/
