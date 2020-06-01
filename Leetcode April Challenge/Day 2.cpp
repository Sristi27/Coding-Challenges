Question : Solution
Write an algorithm to determine if a number n is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Return True if n is a happy number, and False if not.

//C++ Soln

class Solution {
public:
    int sumofdig(int n)
    {
        int s=0;
        while(n!=0)
        {
            s=s+(n%10)*(n%10);
            n=n/10;
        }
        return s;  
    }
    bool isHappy(int n) {
        if (n==1 or n==7)
            return true;
        while(n>=10)
        {
            n=sumofdig(n);
            if(n==1 or n==7)
                return true;
            
        }
        return false;
    }
};
