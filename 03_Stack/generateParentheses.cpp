//
// Created by Ishwar Patel on 03/03/24.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Recursive function to generate valid parentheses combinations
    void generate(int n, int open, int close, string s, vector<string>& result){
        // Base case: if both open and close parentheses counts reach n, add the generated string to the result
        if(open == n && close == n){
            result.push_back(s);
            return;
        }
        // Recursively call the function to add open parentheses if count of open parentheses is less than n
        if(open < n){
            generate(n, open + 1, close, s + '(', result);
        }
        // Recursively call the function to add close parentheses if count of close parentheses is less than open parentheses
        if(close < open){
            generate(n, open, close + 1, s + ')', result);
        }
        return;
    }
public:
    // Function to generate all valid combinations of parentheses pairs
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start the generation process with initial counts of open and close parentheses as 0
        generate(n, 0, 0, "", result);
        return result;
    }

    // Intuition: We use a recursive approach to generate all valid combinations of parentheses.

    // Approach: At each step, we have two choices: add an open parenthesis or add a close parenthesis.
    // We add an open parenthesis if the count of open parentheses is less than n.
    // We add a close parenthesis if the count of close parentheses is less than the count of open parentheses.
    // Base case: When both counts reach n, we add the generated string to the result.

    // Time Complexity: O(2^n), as each position in the output string has two choices (open or close).

    // Space Complexity: O(2^n), as there can be a maximum of 2^n valid combinations.
};
