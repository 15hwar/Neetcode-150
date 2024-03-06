//
// Created by Ishwar Patel on 06/03/24.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Function to calculate the total hours required to eat all bananas at the given eating speed
    long int timeRequired(vector<int> piles, int canEat){
        long int hours = 0; // Total hours required
        for(int num : piles)
            hours += num / canEat + (num % canEat > 0); // Calculate hours required for each pile and sum them up
        return hours; // Return the total hours required
    }
public:
    // Function to find the minimum eating speed required to eat all bananas within h hours
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = *max_element(piles.begin(), piles.end()); // Maximum number of bananas in any pile
        int left = 1; // Minimum possible eating speed
        int right = maxBananas; // Maximum possible eating speed
        int result = right; // Result variable to store the minimum eating speed

        // Binary search to find the minimum eating speed
        while(left <= right) {
            int mid = left + (right - left) / 2; // Calculate mid eating speed

            // Calculate the total hours required to eat all bananas at mid eating speed
            long int numHours = timeRequired(piles, mid);

            // If the total hours required is less than or equal to h, update the result and search in the left half
            if(numHours <= h) {
                result = min(result, mid); // Update the result with the minimum eating speed
                right = mid - 1; // Search in the left half
            }
            else // If the total hours required is greater than h, search in the right half
                left = mid + 1;
        }

        return result; // Return the minimum eating speed
    }

    // Intuition: We want to find the minimum eating speed required to eat all bananas within h hours.

    // Approach: We use binary search to find the minimum eating speed. We set the search space from 1 (minimum possible speed) to the maximum number of bananas in any pile.
    // For each speed, we calculate the total hours required to eat all bananas using the given formula. If the total hours required is less than or equal to h,
    // we update the result with the current speed and search in the left half. Otherwise, we search in the right half.

    // Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in any pile.
    //                  Binary search is performed on the range [1, maxBananas], and for each speed, we calculate the total hours required, which takes O(n) time.

    // Space Complexity: O(1), constant space is used.
};
