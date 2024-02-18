//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to find the top k frequent elements in an array
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Get the size of the input array
        int n = nums.size();

        // Map to store the count of each number
        unordered_map<int, int> numsCount;
        for (const auto& num : nums)
            numsCount[num]++;

        // Buckets to store numbers based on their frequency
        vector<vector<int>> buckets(n + 1);
        for (const auto& counts : numsCount)
            buckets[counts.second].push_back(counts.first);

        // Vector to store the result
        vector<int> result;

        // Iterate through the buckets in reverse order and add elements to the result vector until the size reaches k
        for (int i = n; i > 0; i--) {
            if (result.size() >= k) break; // If k elements are already added to the result, exit the loop
            if (!buckets[i].empty()) // Check if the current bucket is not empty
                result.insert(result.end(), buckets[i].begin(), buckets[i].end()); // Add elements from the current bucket to the result
        }

        return result;
    }
};

/*
Intuition:
- We aim to find the top k frequent elements in the given array.

Approach:
1. Count the frequency of each number using an unordered map.
2. Use buckets to store numbers based on their frequency.
3. Iterate through the buckets in reverse order and add elements to the result vector until the size reaches k.

Time Complexity:
- O(n), where n is the number of elements in the input array.
- Counting the frequency takes O(n), and iterating through the buckets is also O(n).

Space Complexity:
- O(n), where n is the number of elements in the input array.
- We use an unordered map and buckets to store the frequency information.
*/
