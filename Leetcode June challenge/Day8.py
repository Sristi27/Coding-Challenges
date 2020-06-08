Question: Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1

//Python Solution

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n==0:
            return False
        if n&n-1==0:
            return True
        else:
            return False
        
