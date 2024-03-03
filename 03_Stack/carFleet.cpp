//
// Created by Ishwar Patel on 03/03/24.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to calculate the number of car fleets that reach the target
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); // Number of cars

        vector<pair<int, float>> posWithTime; // Vector to store pairs of (position, time to reach target)
        for(int i = 0; i < n; i++)
            posWithTime.push_back({position[i], static_cast<float>(target - position[i]) / speed[i]});

        sort(posWithTime.begin(), posWithTime.end()); // Sort cars based on their initial positions

        int result = 0; // Number of car fleets that reach the target
        float maxTime = 0.0; // Maximum time among cars to reach the target

        // Iterate through the cars in reverse order
        for(int i = n - 1; i >= 0; i--){
            // If the current car takes longer time to reach the target than the maximum time so far,
            // it forms a new car fleet, and we update the maximum time.
            if(posWithTime[i].second > maxTime) {
                maxTime = posWithTime[i].second;
                result++;
            }
        }

        return result;
    }

    // Intuition: We want to calculate the number of car fleets that reach the target. Car fleets are formed by cars moving at the same speed and reaching the target at the same time.

    // Approach: We calculate the time each car takes to reach the target and store the pairs of (position, time) in a vector.
    // We then sort the vector based on the initial positions of the cars.
    // We iterate through the sorted vector and check if each car takes longer time to reach the target than the maximum time so far.
    // If it does, it forms a new car fleet, and we update the maximum time.

    // Time Complexity: O(n log n), where n is the number of cars. Sorting the vector takes O(n log n) time.
    // Space Complexity: O(n), where n is the number of cars (for the vector storing pairs of (position, time)).
};
