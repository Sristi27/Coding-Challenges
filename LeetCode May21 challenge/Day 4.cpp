Non-decreasing Array


Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 

Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
  
  
  
  
  
  
  
C++	
1
class Solution {
2
public:
3
    bool checkPossibility(vector<int>& nums) {
4
        
5
        int count=0;
6
        for(int i=0;i<nums.size()-1;i++)
7
        {
8
            // 0 7 1 8
9
            // 5 7 1 8
10
            if(nums[i+1]<nums[i])
11
            {
12
                if(i-1>=0 && nums[i-1]>nums[i+1]) 
13
                {
14
                    nums[i+1]=nums[i];
15
                }
16
                else
17
                {
18
                    nums[i]=nums[i+1];
19
                }
20
                break;
21
            }
22
            
23
        }
24
        
25
        for(int i=0;i<nums.size()-1;i++)
26
        {
27
            if(nums[i]>nums[i+1])
28
            return false;
29
        }
30
        
31
        return true;
32
    }
33
};
