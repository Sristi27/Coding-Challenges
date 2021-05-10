Construct Target Array With Multiple Sums

Given an array of integers target. From a starting array, A consisting of all 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
You may repeat this procedure as many times as needed.
Return True if it is possible to construct the target array from A otherwise return False.

 

Example 1:

Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
Example 2:

Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
Example 3:

Input: target = [8,5]
Output: true
 

Constraints:

N == target.length
1 <= target.length <= 5 * 10^4
1 <= target[i] <= 10^9
   Hide Hint #1  
Given that the sum is strictly increasing, the largest element in the target must be formed in the last step by adding the total sum in the previous step. Thus, we can simulate the process in a reversed way.
   Hide Hint #2  
Subtract the largest with the rest of the array, and put the new element into the array. Repeat until all elements become one






C++	
1
class Solution {
2
public:
3
    bool isPossible(vector<int>& target) {  
4
      long n=target.size(),sum;
5
        // o(nlogn)
6
      while(1)   //n
7
      {
8
          //1 1 2
9
          sum=0;
10
          sort(target.begin(),target.end()); //nlogn
11
          if(target[0]==1 && target[n-1]==1) return true; //n
12
          for(int i=0;i<n;i++) sum+=target[i];
13
          long diff=sum-target[n-1];  //4-2=2
14
          if(diff==1) return true;   // 1 1000
15
          if(diff>=target[n-1] || diff==0 || target[n-1]%diff==0) return false;
16
          //.1 2 2                //2 2           //20 5
17
          target[n-1]%=diff; 
18
          //13 5
19
          
20
      }
21
        
22
        return false;
23
    }
24
};
