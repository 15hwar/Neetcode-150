//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector>
#include <unordered_set>

class Solution {
public:
    // Function to check if a given vector contains any duplicate elements.
    // Parameters:
    // - nums: Input vector of integers.
    // Returns:
    // - true if there are duplicate elements, otherwise false.
    bool containsDuplicate(const std::vector<int>& nums) {
        // Initialize an unordered_set to store unique elements encountered so far.
        std::unordered_set<int> uniqueNums;

        // Iterate through each element in the input vector.
        for(const auto& num : nums) {
            // If the current element is already in the set, return true indicating duplicates.
            if(uniqueNums.count(num) > 0)
                return true;
            // Otherwise, insert the element into the set to keep track of unique elements.
            uniqueNums.insert(num);
        }

        // If no duplicates were found, return false.
        return false;
    }
};

// Intuition:
// We can use an unordered_set to keep track of unique elements encountered while traversing the input vector.
// During traversal, if we encounter an element that already exists in the set, we return true, indicating the presence of a duplicate.
// If no duplicates are found after traversing the entire vector, we return false.

// Approach:
// 1. Initialize an unordered_set to store unique elements encountered so far.
// 2. Iterate through each element in the input vector.
// 3. For each element, check if it already exists in the set.
//    - If it does, return true indicating the presence of a duplicate.
//    - If it doesn't, insert the element into the set.
// 4. If no duplicates were found after traversing the entire vector, return false.

// Time Complexity:
// The time complexity of this solution is O(n), where n is the number of elements in the input vector.
// This is because the average case time complexity of insert and search operations in an unordered_set is O(1),
// and we perform these operations for each element in the vector.

// Space Complexity:
// The space complexity of this solution is also O(n), where n is the number of elements in the input vector.
// This is because, in the worst case, the unordered_set may store all the elements of the input vector.

