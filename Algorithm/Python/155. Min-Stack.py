# Problem from: https://leetcode.com/problems/min-stack/description/

"""
Min Stack

Design a stack that supports push, pop, and retrieving the minimum element in constant time. 
- push(x): Push element x onto stack.
- pop(): Removes the elemnt on top of the stack.
- top(): Get the top element.
- getMin(): Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
"""

class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.items = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        # If stack is empty, then just append 
        if self.items == []:
            self.items.append((x, x))
        else:
            # Get the current minimum from the last element
            currentMin = self.items[-1][1]
            self.items.append((x, min(x, currentMin)))
        

    def pop(self):
        """
        :rtype: void
        """
        self.items.pop()[0]

    def top(self):
        """
        :rtype: int
        """
        return self.items[-1][0]

    def getMin(self):
        """
        :rtype: int
        """
        return self.items[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()