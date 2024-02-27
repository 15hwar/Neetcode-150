//
// Created by Ishwar Patel on 27/02/24.
//
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to evaluate the given reverse Polish notation (RPN) expression.
    // Arguments:
    // - tokens: a vector of strings representing the RPN expression.
    // Returns:
    // - The result of the evaluation.
    int evalRPN(vector<string>& tokens) {
        // Stack to store integers encountered in the expression.
        stack<int> integers;

        // Iterate through each token in the expression.
        for (string num : tokens) {
            // If the token is a number (either single-digit or multi-digit), push it onto the stack.
            if (num.size() > 1 || isdigit(num[0]))
                integers.push(stoi(num));
            else {
                // If the token is an operator, pop the top two numbers from the stack and perform the operation.
                int num2 = integers.top(); integers.pop();
                int num1 = integers.top(); integers.pop();
                switch (num[0]) {
                    case '+': integers.push(num1 + num2); break;
                    case '-': integers.push(num1 - num2); break;
                    case '*': integers.push(num1 * num2); break;
                    case '/': integers.push(num1 / num2); break;
                }
            }
        }
        // The result is the top element of the stack.
        return integers.top();
    }
};

/*
**Intuition:**
- Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical notation in which every operator follows all of its operands.
- The problem is to evaluate an RPN expression containing integers and operators (+, -, *, /).
- We can use a stack data structure to store integers encountered in the expression and perform operations when encountering operators.

**Approach:**
- Iterate through each token in the expression.
- If the token is a number (either single-digit or multi-digit), push it onto the stack.
- If the token is an operator, pop the top two numbers from the stack, perform the operation, and push the result back onto the stack.
- After processing all tokens, the result is the top element of the stack.

**Time Complexity:** O(n), where n is the number of tokens in the expression. We iterate through each token once.

**Space Complexity:** O(n), where n is the number of tokens in the expression. This is because we use a stack to store integers.
*/
