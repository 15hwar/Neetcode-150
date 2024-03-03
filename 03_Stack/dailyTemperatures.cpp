//
// Created by Ishwar Patel on 03/03/24.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Function to find the number of days until warmer temperatures for each day
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(); // Number of days
        vector<int> result(n); // Vector to store the result

        stack<pair<int,int>> stk; // Stack to store pairs of (day, temperature)

        for(int i = 0; i < n; i++) {
            int currDay = i; // Current day
            int currTemp = temperatures[i]; // Current temperature

            // While stack is not empty and the temperature of the current day is higher than the temperature of the top of the stack
            while(!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first; // Previous day with lower temperature
                int prevTemp = stk.top().second; // Temperature on the previous day
                stk.pop(); // Remove the top element from the stack

                // Calculate the number of days until warmer temperatures and store it in the result array
                result[prevDay] = currDay - prevDay;
            }

            // Push the current day and temperature onto the stack
            stk.push({currDay, currTemp});
        }

        return result; // Return the result array
    }

    // Intuition: We want to find the number of days until warmer temperatures for each day.

    // Approach: We iterate through the given temperatures. For each temperature, we check the temperatures of the previous days stored in the stack.
    // If the temperature of the current day is higher than the temperature of a previous day, we update the result array with the number of days until warmer temperatures.
    // We use a stack to store pairs of (day, temperature) to keep track of the previous temperatures.

    // Time Complexity: O(n), where n is the number of days.
    // Space Complexity: O(n), where n is the number of days (for the stack).
};
