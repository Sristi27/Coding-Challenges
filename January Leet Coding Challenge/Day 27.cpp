//Important


Concatenation of Consecutive Binary Numbers.
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
 

Constraints:

1 <= n <= 105
   Hide Hint #1  
Express the nth number value in a recursion formula and think about how we can do a fast evaluation.
C++	
1
#define N 1000000007
2
class Solution {
3

//o(nlogn)

public:
4
    int concatenatedBinary(int n) {
5
        long ans=0;
6
        for(int i=1;i<=n;i++)
7
        {
8
            int len=0,x=i;
9
            while(x>0)
10
            {
11
                ++len;
12
                x=x/2;
13
                //count in orders of 2  -  8 4 2 1
14
            }
15
            ans=(ans<<len); //left shift till the length
16
            ans=ans%N+i;
17
        }
18
        return ans%N;
19
        return 0;
20
    }
21
};
