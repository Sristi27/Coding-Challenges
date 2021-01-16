Boats to Save People -- 2pointer method

You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104
C++	
     {
            count++;
            if(people[i]+people[j]<=limit)
            i++;
            j--;
        }
        
        return count;
    }
};
1
class Solution {
2
public:
3
    int numRescueBoats(vector<int>& people, int limit) {
4
        sort(people.begin(),people.end());
5
        int i=0,j=people.size()-1,count=0;
6
        while(i<=j)
7
        {
8
            count++;
9
            if(people[i]+people[j]<=limit)
10
            i++;
11
            j--;
12
        }
13
        
14
        return count;
15
    }
16
};
