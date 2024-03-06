//
// Created by Ishwar Patel on 06/03/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    // Function to search for a target element in a sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // Size of the array
        int left = 0; // Left pointer
        int right = n - 1; // Right pointer

        // Binary search loop
        while(left <= right) {
            int mid = left + (right - left) / 2; // Calculate mid index

            if(nums[mid] == target) // If target found at mid index, return mid
                return mid;
            else if(nums[mid] < target) // If target is greater than mid element, search in the right half
                left = mid + 1;
            else // If target is smaller than mid element, search in the left half
                right = mid - 1;
        }

        return -1; // Target not found
    }

    // Intuition: We want to search for a target element in a sorted array.

    // Approach: We use binary search to find the target element. We initialize two pointers, left and right,
    // to the beginning and end of the array respectively. We then repeatedly divide the array in half
    // and update the pointers based on the comparison of the target with the middle element.

    // Time Complexity: O(log n), where n is the number of elements in the array. Binary search reduces the search space by half in each iteration.
    // Space Complexity: O(1), constant space is used.
};
