//
// Created by Ishwar Patel on 21/02/24.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the input array to optimize the search
        sort(nums.begin(), nums.end());

        // Initialize a vector to store the result
        vector<vector<int>> result;

        // Iterate through the array
        for(int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for the first element of the triplet
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // Initialize pointers for the second and third elements of the triplet
            int j = i + 1, k = nums.size() - 1;

            // Loop to find the remaining two elements
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    // If found, add the triplet to the result vector
                    result.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for the second element
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicates for the third element
                    while(j < k && nums[k] == nums[k - 1]) k--;

                    // Move the pointers
                    j++;
                    k--;
                } else if(sum < 0) {
                    // If the sum is less than zero, increment j
                    j++;
                } else {
                    // If the sum is greater than zero, decrement k
                    k--;
                }
            }
        }

        return result;
    }
};

/*
Intuition:
- The goal is to find all unique triplets in the array that sum up to zero.
- Sorting the array enables the use of a two-pointer approach, which reduces the time complexity.
- By fixing one element and then finding the other two elements using two pointers, we ensure that the solution is unique.

Approach:
1. Sort the array to easily skip duplicates and optimize the search.
2. Iterate through the array. For each element, fix it as the first element of the triplet.
3. Use two pointers, one starting from the next element and the other starting from the last element, to find the remaining two elements.
4. Skip duplicates to avoid duplicates in the result.
5. If the sum of the triplet is zero, add it to the result vector.
6. Adjust the pointers based on whether the sum is greater than zero or less than zero.
7. Continue until all possible triplets are examined.

Space Complexity:
- The space complexity is O(n) due to the storage of the result vector.

Time Complexity:
- The time complexity is O(n^2) where n is the size of the input array.
- Sorting the array takes O(n log n), and for each element, the two-pointer approach takes O(n) in the worst case.
- Therefore, the overall time complexity is dominated by the sorting step and is O(n log n).
*/
