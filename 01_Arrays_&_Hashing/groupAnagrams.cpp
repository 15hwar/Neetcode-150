//
// Created by Ishwar Patel on 18/02/24.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to group anagrams together
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store anagrams where sorted string is the key and vector of anagrams as value
        unordered_map<string, vector<string>> mapAnagrams;

        // Iterate through each string in the input vector
        for(const auto& str : strs) {
            // Create a temporary string to store the sorted version of the current string
            string tempString = str;
            sort(tempString.begin(), tempString.end()); // Sort the characters of the string

            // Add the original string to the vector corresponding to its sorted version in the unordered map
            mapAnagrams[tempString].push_back(str);
        }

        // Vector to store grouped anagrams
        vector<vector<string>> anagrams;

        // Iterate through the unordered map and add vectors of anagrams to the result vector
        for(const auto& i : mapAnagrams) {
            anagrams.push_back(i.second);
        }

        return anagrams;
    }
};

/*
Intuition:
- Anagrams are words that have the same characters but in a different order.
- We aim to group anagrams together.

Approach:
1. Create an unordered map where the key is the sorted version of each string, and the value is a vector of strings that are anagrams of each other.
2. Iterate through each string in the input vector.
3. Sort the characters of each string to get its canonical form.
4. Use the sorted string as the key in the unordered map and add the original string to the corresponding vector.
5. Iterate through the unordered map and add vectors of anagrams to the result vector.

Time Complexity:
- O(n * k log k), where n is the number of strings and k is the maximum length of a string.
- Sorting each string takes O(k log k) time, and we do this for each of the n strings.

Space Complexity:
- O(n * k), where n is the number of strings and k is the maximum length of a string.
- We store the sorted strings in the unordered map, which may contain all input strings in the worst case.
*/
