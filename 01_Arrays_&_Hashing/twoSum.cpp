//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to find indices of two numbers that add up to a target
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store visited numbers and their indices
        std::unordered_map<int, int> visitedNums;

        // Iterate through the numbers
        for(int i = 0; i < nums.size(); i++) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];

            // Check if the complement is in the visited numbers map
            if(visitedNums.count(complement)) {
                // If complement found, return indices of complement and current number
                return {visitedNums[complement], i};
            }

            // Store the current number and its index in the visited numbers map
            visitedNums[nums[i]] = i;
        }

        // If no solution found, return an empty vector
        return {};
    }
};

/*
Intuition:
- We aim to find two numbers in the given array that sum up to the target.
- We utilize a hash map to store the visited numbers and their indices.

Approach:
1. Initialize an unordered map to store visited numbers and their indices.
2. Iterate through the array.
3. For each number, calculate its complement needed to reach the target.
4. Check if the complement exists in the map. If yes, return the indices.
5. Otherwise, store the current number and its index in the map.
6. If no solution is found, return an empty vector.

Time Complexity:
- O(n), where n is the number of elements in the array.
- We iterate through the array once, and each lookup operation in the unordered map takes constant time on average.

Space Complexity:
- O(n), where n is the number of elements in the array.
- We may store all elements of the array in the unordered map in the worst case.
*/
