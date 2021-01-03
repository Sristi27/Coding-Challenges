Beautiful Arrangement

Solution
Suppose you have n integers from 1 to n. We define a beautiful arrangement as an array that is constructed by these n numbers successfully if one of the following is true for the ith position (1 <= i <= n) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1, 2]:
Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
The second beautiful arrangement is [2, 1]:
Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 15









C++	
1
class Solution {
2
public:
3
    void swap(vector<int>&nums,int src,int dest)
4
    {
5
        int temp=nums[src];
6
        nums[src]=nums[dest];
7
        nums[dest]=temp;
8
    }
9
    int ans=0;
10
    int countArrangement(int n) {
11
        vector<int>nums(n+1);
12
        for(int i=1;i<=n;i++)
13
            nums[i]=i;
14
        //perform dfs from 1
15
        permute(nums,1);
16
        return ans;
17
    }
18
    void permute(vector<int>nums,int src)
19
    {
20
        int n=nums.size();
21
        if(src==n)
22
        {
            ans++;   //soln found
            return;
26
        }
        for(int i=src;i<n;i++)
29
        {
30
            if(nums[i]%src==0 || src % nums[i]==0)
31
            {
32
                swap(nums,i,src);
33
                permute(nums,src+1);
34
                swap(nums,src,i);
35
            }
36
        }
37
    }
38
};
