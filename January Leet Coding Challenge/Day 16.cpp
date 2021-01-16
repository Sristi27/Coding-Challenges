Kth Largest Element in an Array
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.




C++	
1
class Solution {
2
public:
3
    int findKthLargest(vector<int>& nums, int k) {
4
        
5
        //o(nlogn)
6
        // sort(nums.begin(),nums.end());
7
        // return nums[nums.size()-k];
8
        
9
        
10
        //using max-heap - o(n+klogn)
11
        priority_queue<int,vector<int>>pq;
12
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
13
        while(--k) pq.pop();
14
        return pq.top();
15
    }
16
};
