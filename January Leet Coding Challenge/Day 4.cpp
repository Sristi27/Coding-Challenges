Kth Missing Positive Number.
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
C++	




1
class Solution {
2
public:
3
    int findKthPositive(vector<int>& arr, int k) {
4
        vector<int>num;
5
        int m=*max_element(arr.begin(),arr.end());
6
        for(int i=1;i<m;i++)
7
        {
8
            if(find(arr.begin(),arr.end(),i)==arr.end())
9
                num.push_back(i);
10
        }
11
        if(num.size()==0)
12
            return m+k;
13
        else
14
        {
15
            if(k<=num.size()) return num[k-1];
16
            else return m+k-num.size();
17
        }
18
    }
19
};
