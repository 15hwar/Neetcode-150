//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end()); // Create a HashSet from the input vector

        int maxCount = 0; // Initialize the maximum length of consecutive sequence

        // Iterate through each number in the HashSet
        for (int num : uniqueNums) {
            if (uniqueNums.find(num - 1) == uniqueNums.end()) { // Check if num - 1 exists in the HashSet
                int count = 1; // Initialize the length of the consecutive sequence starting from num
                while (uniqueNums.find(num + 1) != uniqueNums.end()) { // Increment num until no consecutive number found
                    num++;
                    count++;
                }
                maxCount = max(maxCount, count); // Update the maximum length of consecutive sequence
            }
        }

        return maxCount; // Return the maximum length of consecutive sequence
    }
};

// Intuition:
// The problem requires finding the length of the longest consecutive sequence in an unsorted array of integers.
// Consecutive elements form sequences, and we aim to find the length of the longest such sequence.

// Approach:
// - We create a HashSet from the input vector for fast O(1) lookup.
// - We iterate through each number in the HashSet.
// - For each number, we check if num - 1 exists in the HashSet. If it doesn't, it means num is the start of a consecutive sequence.
// - We then increment num until no more consecutive numbers are found in the HashSet, counting the length of the sequence.
// - We update the maximum length of consecutive sequence encountered so far.
// - Finally, we return the maximum length of consecutive sequence found.

// Time Complexity:
// - The time complexity of this solution is O(n), where n is the number of elements in the input array.
// - This is because we iterate through the HashSet only once, and each operation (insertion, lookup) in the HashSet takes O(1) time.

// Space Complexity:
// - The space complexity is O(n), where n is the number of elements in the input array.
// - This is because we use a HashSet to store unique numbers from the input array.
