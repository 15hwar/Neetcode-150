//
// Created by Ishwar Patel on 27/02/24.
//
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to check if a given string containing brackets is valid.
    // Arguments:
    // - s: a string containing brackets.
    // Returns:
    // - true if the string is valid, false otherwise.
    bool isValid(string s) {
        // Initialize a stack to store opening brackets.
        stack<char> st;
        // Map to store the mappings of opening and closing brackets.
        unordered_map<char, char> brackets = {
                {'(', ')'},
                {'[', ']'},
                {'{', '}'}
        };

        // Iterate through each character in the string.
        for (char ch : s) {
            // If the current character is an opening bracket, push it onto the stack.
            if (brackets.count(ch))
                st.push(ch);
            else {
                // If the stack is empty or the current character does not match the corresponding opening bracket,
                // the string is invalid.
                if (st.empty())
                    return false;
                if (ch != brackets[st.top()])
                    return false;
                st.pop(); // Pop the matched opening bracket from the stack.
            }
        }
        // If the stack is empty, all brackets are matched and the string is valid.
        return st.empty();
    }
};

/*
**Intuition:**
- The problem is to determine whether the given string containing brackets is valid, i.e., whether all the opening brackets are properly closed.
- We can use a stack data structure to keep track of the opening brackets encountered so far and check if the corresponding closing brackets match.

**Approach:**
1. Initialize an empty stack to store opening brackets.
2. Iterate through each character in the string.
   - If the current character is an opening bracket, push it onto the stack.
   - If the current character is a closing bracket:
     - If the stack is empty, return false (no matching opening bracket).
     - If the top of the stack does not match the corresponding opening bracket, return false.
     - Otherwise, pop the top of the stack (matching opening bracket).
3. After processing all characters, if the stack is empty, return true (all brackets are properly matched); otherwise, return false.

**Time Complexity:** O(n), where n is the length of the input string. We traverse the string once.

**Space Complexity:** O(n), where n is the length of the input string. In the worst case, the stack can contain all opening brackets if there are no corresponding closing brackets.
*/
