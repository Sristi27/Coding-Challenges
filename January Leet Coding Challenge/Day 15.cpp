Get Maximum in Generated Array

Solution
You are given an integer n. An array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.

 

Example 1:

Input: n = 7
Output: 3
Explanation: According to the given rules:
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.
Example 2:

Input: n = 2
Output: 1
Explanation: According to the given rules, the maximum between nums[0], nums[1], and nums[2] is 1.
Example 3:

Input: n = 3
Output: 2
Explanation: According to the given rules, the maximum between nums[0], nums[1], nums[2], and nums[3] is 2.
 

Constraints:

0 <= n <= 100
   Hide Hint #1  
Try generating the array.
   Hide Hint #2  
Make sure not to fall in the base case of 0.
C++	



1
class Solution {
2
public:
3
    int getMaximumGenerated(int n) {
4
        vector<int>nums(n+1,0);
5
        if(n==0) return 0;
6
        if(n==1) return 1;
7
        nums[0]=0;
8
        nums[1]=1;
9
        int i=1;
10
        while(i*2<n)
11
        {
12
            nums[i*2]=nums[i];
13
            nums[i*2+1]=nums[i]+nums[i+1];
14
            i++;
15
        }
16
        sort(nums.begin(),nums.end());
17
        return nums[nums.size()-1];
18
    }
19
};
