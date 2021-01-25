Check If All 1's Are at Least Length K Places Away.(O(n) time complexity and O(1) Space complexity)


Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

 

Example 1:



Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:



Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
Example 3:

Input: nums = [1,1,1,1,1], k = 0
Output: true
Example 4:

Input: nums = [0,1,0,1], k = 1
Output: true
 

Constraints:

1 <= nums.length <= 105
0 <= k <= nums.length
nums[i] is 0 or 1
   Hide Hint #1  
Each time you find a number 1, check whether or not it is K or more places away from the next one. If it's not, return false.
C++	
prevIdx=i;
1
class Solution {
2
public:
3
    bool kLengthApart(vector<int>& nums, int k) {
4
    
5
        int prevIdx=-1;
6
        int n=nums.size();
7
        if(n==0) return true;
8
        for(int i=0;i<n;i++)
9
        {
10
            if(nums[i]==1)
11
            {
12
                if(prevIdx==-1) prevIdx=i;
13
                else
14
                 {
15
                      if(i-prevIdx-1<k) return false;
16
                      prevIdx=i;
17
                  }
18
            }
19
        }
20
        return true;
21
    }
22
};
