//
// Created by Ishwar Patel on 20/02/24.
//
#include <string> // Include necessary header files
using namespace std;

class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1; // Initialize left and right pointers

        // Loop until left pointer is less than or equal to right pointer
        while (l <= r) {
            // Skip non-alphanumeric characters from the left side
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            // Skip non-alphanumeric characters from the right side
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            // Check if characters at left and right pointers are equal ignoring case
            if (tolower(s[l]) != tolower(s[r]))
                return false; // If not equal, return false
            l++; // Move left pointer to the right
            r--; // Move right pointer to the left
        }
        return true; // If the string is a palindrome, return true
    }
};
// Intuition:
// A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward.
// The problem requires determining whether a given string is a palindrome, ignoring cases and considering only alphanumeric characters.

// Approach:
// - We use two pointers, one starting from the beginning of the string (left pointer) and the other from the end (right pointer).
// - We iterate until the left pointer is less than or equal to the right pointer.
// - At each step, we skip non-alphanumeric characters from both ends.
// - We compare characters at the left and right pointers, ignoring case.
// - If characters are not equal, we return false as the string is not a palindrome.
// - Otherwise, we move both pointers towards each other.
// - If we reach the end of the loop without finding any unequal characters, the string is a palindrome, and we return true.

// Time Complexity:
// - The time complexity of this solution is O(n), where n is the length of the input string.
// - We iterate through the string once, and each character comparison operation takes constant time.

// Space Complexity:
// - The space complexity is O(1) as we only use a constant amount of extra space for variables regardless of the input size.
