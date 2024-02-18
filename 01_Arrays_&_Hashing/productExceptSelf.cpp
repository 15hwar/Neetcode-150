//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector> // Include necessary header files

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize result vector with all 1s

        int prefixMul = 1, suffixMul = 1; // Initialize prefix and suffix multipliers

        // Calculate prefix products and store them in result
        for (int i = 0; i < n; i++) {
            result[i] *= prefixMul; // Update result with prefix product
            prefixMul *= nums[i];   // Update prefix product
        }

        // Calculate suffix products and update result accordingly
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffixMul; // Update result with suffix product
            suffixMul *= nums[i];   // Update suffix product
        }

        return result; // Return the final result vector
    }
};

// Intuition:
// To find the product of all elements except the current element, we can calculate prefix products
// and suffix products for each element. Multiplying the prefix and suffix products of each element
// gives us the desired result.

// Approach:
// 1. Initialize a result vector with all elements set to 1.
// 2. Iterate through the array to calculate prefix products. Update the result vector as we go.
// 3. Iterate through the array in reverse to calculate suffix products. Update the result vector accordingly.
// 4. Return the final result vector.

// Time Complexity:
// The time complexity of this solution is O(n), where n is the size of the input array. We traverse the array
// twice in separate loops.

// Space Complexity:
// The space complexity is O(n), where n is the size of the input array. This is due to the additional space
// used for the result vector.
