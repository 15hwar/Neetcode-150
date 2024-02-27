//
// Created by Ishwar Patel on 27/02/24.
//
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Stack to store the main elements.
    stack<int> minStack;  // Stack to store the minimum elements.

public:
    // Constructor to initialize the MinStack.
    MinStack() {

    }

    // Function to push a value onto the stack.
    // Arguments:
    // - val: the value to be pushed onto the stack.
    void push(int val) {
        // If the minStack is empty, push the value onto both stacks.
        if (minStack.empty()) {
            mainStack.push(val);
            minStack.push(val);
        } else {
            // Otherwise, push the value onto the mainStack and also push the minimum of the current minimum and the value onto the minStack.
            int minTop = minStack.top();
            mainStack.push(val);
            minStack.push(min(minTop, val));
        }
    }

    // Function to pop the top element from the stack.
    void pop() {
        // Pop both stacks to remove the top element.
        mainStack.pop();
        minStack.pop();
    }

    // Function to get the top element of the stack.
    // Returns:
    // - The top element of the mainStack.
    int top() {
        return mainStack.top();
    }

    // Function to get the minimum element in the stack.
    // Returns:
    // - The top element of the minStack, which represents the current minimum in the stack.
    int getMin() {
        return minStack.top();
    }
};

/*
**Intuition:**
- The problem is to implement a stack that supports push, pop, top, and retrieving the minimum element in constant time.
- We can use an additional stack, called minStack, to keep track of the minimum element at any point.
- Whenever we push a new element onto the main stack, we compare it with the top element of the minStack and push the smaller value onto the minStack.

**Approach:**
- We maintain two stacks: mainStack to store the main elements and minStack to store the minimum elements.
- When pushing a new element onto the stack, we compare it with the top element of the minStack.
  - If the minStack is empty, we push the new element onto both stacks.
  - Otherwise, we push the new element onto the mainStack and also push the minimum of the current minimum and the new element onto the minStack.
- When popping an element from the stack, we simply pop from both stacks.
- Getting the top element of the stack and retrieving the minimum element are constant-time operations as we directly access the top elements of the respective stacks.

**Time Complexity:** O(1) for all operations (push, pop, top, getMin) as they involve only stack operations.

**Space Complexity:** O(n) where n is the number of elements in the stack. This is because we are using an additional stack (minStack) to store the minimum elements.
*/
