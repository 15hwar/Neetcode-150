//
// Created by Ishwar Patel on 18/02/24.
//
#include <string> // Include necessary header files
#include <vector>

using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string encodedStr;

        // Iterate through each string in the vector
        for (const string &str : strs) {
            // Encode each string by concatenating its length and the string itself with a delimiter "#"
            encodedStr += to_string(str.length()) + "#" + str;
        }

        return encodedStr; // Return the encoded string
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrs;
        int i = 0;

        // Decode the encoded string
        while (i < s.length()) {
            // Find the delimiter "#" that separates the length of the string
            int delimiterIndex = s.find("#", i);
            if (delimiterIndex == string::npos) break; // Handle edge case
            // Extract the length of the string from the encoded string
            int strLength = stoi(s.substr(i, delimiterIndex - i));
            // Extract the string itself from the encoded string
            decodedStrs.push_back(s.substr(delimiterIndex + 1, strLength));
            // Move the index to the next position after the decoded string
            i = delimiterIndex + strLength + 1;
        }

        return decodedStrs; // Return the decoded strings
    }
};

// Intuition:
// The problem involves encoding and decoding a list of strings into a single string and vice versa. We need to ensure that the decoding process retrieves the original list of strings.

// Approach:
// - For encoding, iterate through each string in the vector and concatenate its length and the string itself with a delimiter "#".
// - For decoding, iterate through the encoded string, find the delimiter "#" that separates the length of each string, extract the length and the string itself, and push it into a vector.
// - Continue this process until the end of the encoded string is reached.

// Time Complexity:
// - Encoding: O(n), where n is the total number of characters in all strings in the vector. We iterate through each string once.
// - Decoding: O(n), where n is the length of the encoded string. We iterate through the encoded string once.

// Space Complexity:
// - Encoding: O(n), where n is the total number of characters in all strings in the vector. We create a single encoded string.
// - Decoding: O(m), where m is the total number of characters in all decoded strings. We create a vector to store all decoded strings.
