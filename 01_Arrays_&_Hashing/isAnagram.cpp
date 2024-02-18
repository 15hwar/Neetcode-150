//
// Created by Ishwar Patel on 18/02/24.
//
#include <string>
#include <vector>

class Solution {
public:
    // Function to check if two strings are anagrams of each other.
    // Parameters:
    // - s: First input string.
    // - t: Second input string.
    // Returns:
    // - true if the strings are anagrams, otherwise false.
    bool isAnagram(const std::string& s, const std::string& t) {
        // Initialize a vector to store the count of each letter in the alphabet.
        std::vector<int> letterCount(26);

        // Count the occurrence of each letter in the first string.
        for (const auto& ch : s)
            letterCount[ch - 'a']++;

        // Decrease the count of each letter based on its occurrence in the second string.
        for (const auto& ch : t)
            letterCount[ch - 'a']--;

        // Check if all counts in the vector are zero, indicating an anagram.
        for (const auto& count : letterCount)
            if (count != 0)
                return false;

        // If all counts are zero, the strings are anagrams.
        return true;
    }
};

// Intuition:
// An anagram is formed by rearranging the letters of one string to form another string.
// To determine if two strings are anagrams, we can count the occurrences of each letter in both strings.
// If the counts of all letters are the same in both strings, they are anagrams; otherwise, they are not.

// Approach:
// 1. Initialize a vector to store the count of each letter in the alphabet, initialized to zeros.
// 2. Traverse the first string and increment the count of each letter encountered.
// 3. Traverse the second string and decrement the count of each letter encountered.
// 4. After traversing both strings, check if all counts in the vector are zero.
//    - If any count is non-zero, return false, indicating that the strings are not anagrams.
//    - If all counts are zero, return true, indicating that the strings are anagrams.

// Time Complexity:
// The time complexity of this solution is O(n), where n is the length of the input strings.
// This is because we traverse both strings once to count the occurrences of each letter,
// and then we iterate over the count vector, which has a constant size of 26.

// Space Complexity:
// The space complexity of this solution is O(1), as the count vector has a fixed size of 26,
// which does not depend on the input size. Therefore, the space complexity is constant.
