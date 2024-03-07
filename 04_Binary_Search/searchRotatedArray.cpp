//
// Created by Ishwar Patel on 07/03/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    // Function to search for a target element in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // Size of the array
        int left = 0, right = n - 1; // Pointers for binary search

        // Binary search loop
        while(left <= right) {
            int mid = left + (right - left) / 2; // Calculate mid index

            // If the target is found at mid index, return mid
            if(nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if(nums[mid] >= nums[left]) {
                // If target is within the sorted left half, search in the left half
                if(target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                    // If not, search in the right half
                else
                    left = mid + 1;
            }
                // If the right half is sorted
            else {
                // If target is within the sorted right half, search in the right half
                if(target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                    // If not, search in the left half
                else
                    right = mid - 1;
            }
        }

        return -1; // Target not found
    }

    // Intuition: We want to search for a target element in a rotated sorted array.

    // Approach: We use binary search to find the target element. We compare the middle element with the leftmost and rightmost elements to determine
    // whether the left half or the right half is sorted. Based on that, we decide which half to search in. We continue this process until we find the target
    // or the search space is exhausted.

    // Time Complexity: O(log n), where n is the number of elements in the array. Binary search reduces the search space by half in each iteration.

    // Space Complexity: O(1), constant space is used.
};
