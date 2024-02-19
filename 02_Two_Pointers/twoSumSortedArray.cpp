//
// Created by Ishwar Patel on 20/02/24.
//
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find two numbers in a sorted array that sum up to a target.
    // Arguments:
    // - numbers: a sorted vector of integers.
    // - target: the target sum.
    // Returns:
    // - A vector containing the indices of the two numbers that sum up to the target.
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialize two pointers, one at the beginning and one at the end of the array.
        int left = 0, right = numbers.size() - 1;

        // Iterate until the pointers meet.
        while (left < right) {
            // Calculate the sum of the current elements pointed by the left and right pointers.
            int sum = numbers[left] + numbers[right];

            // If the sum is equal to the target, return the indices of the two numbers.
            if (sum == target)
                return {left + 1, right + 1};
                // If the sum is greater than the target, move the right pointer to the left.
            else if (sum > target)
                right--;
                // If the sum is less than the target, move the left pointer to the right.
            else
                left++;
        }

        // If no such pair is found, return an empty vector.
        return {};
    }
};
/*
**Intuition:**
- The problem is asking to find two numbers that sum up to a target. Since the input array is sorted, we can employ a two-pointer approach to efficiently find the pair.
- We start with two pointers, one at the beginning and one at the end of the array, and gradually move them towards each other.
- As the array is sorted, moving the left pointer to the right increases the sum, and moving the right pointer to the left decreases the sum. This allows us to explore different pairs efficiently.

**Approach:**
1. Initialize two pointers `left` and `right` at the beginning and end of the array, respectively.
2. While `left` is less than `right`, do:
   - Calculate the sum of the elements at indices `left` and `right`.
   - If the sum equals the target, return the indices of the two elements.
   - If the sum is greater than the target, decrement `right` to decrease the sum.
   - If the sum is less than the target, increment `left` to increase the sum.
3. If no such pair is found, return an empty vector.

**Time Complexity:** O(n), where n is the number of elements in the array. The algorithm traverses the array once with two pointers.

**Space Complexity:** O(1), as the algorithm uses only a constant amount of extra space regardless of the input size.
*/
