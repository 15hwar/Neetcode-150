//
// Created by Ishwar Patel on 06/03/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the minimum element in a rotated sorted array
    int findMin(vector<int>& nums) {
        int n = nums.size(); // Size of the array
        int left = 0, right = n - 1; // Pointers for binary search
        int minVal = nums[0]; // Initialize minVal with the first element

        // Binary search loop
        while(left <= right) {
            // If the array is sorted, the minimum element is at nums[left]
            if(nums[left] < nums[right]) {
                minVal = min(minVal, nums[left]); // Update minVal with the minimum of minVal and nums[left]
                break; // Break the loop
            }

            int mid = left + (right - left) / 2; // Calculate mid index

            minVal = min(minVal, nums[mid]); // Update minVal with the minimum of minVal and nums[mid]

            // Check if the array is sorted from mid to right
            if(nums[mid] >= nums[left])
                left = mid + 1; // If yes, search in the right half
            else
                right = mid - 1; // If no, search in the left half
        }

        return minVal; // Return the minimum element
    }

    // Intuition: We want to find the minimum element in a rotated sorted array.

    // Approach: We use binary search to find the minimum element. We compare the middle element with the leftmost and rightmost elements to determine
    // whether the array is sorted or rotated. If the array is sorted, the minimum element is at the leftmost position. If not, we adjust the pointers
    // accordingly to continue the search.

    // Time Complexity: O(log n), where n is the number of elements in the array. Binary search reduces the search space by half in each iteration.

    // Space Complexity: O(1), constant space is used.
};
