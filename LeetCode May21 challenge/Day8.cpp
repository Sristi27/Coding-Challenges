Super Palindromes
Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

 

Example 1:

Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
Example 2:

Input: left = "1", right = "2"
Output: 1
 

Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018].
left is less than or equal to right.










C++	
1
class Solution {
2
public:
3
    bool isPalindrome(long long x)
4
    {
5
        long long temp=x,res=0;
6
        while(temp)
7
        {
8
            res=res*10+temp%10;
9
            temp/=10;
10
        }
11
        return res==x;
12
    }
13
    int superpalindromesInRange(string left, string right) {
14
        long long l=stoll(left),r=stoll(right);
15
        int count=0;
16
        //even
17
        for(int i=1;i<100000;i++)
18
        {
19
            string s=to_string(i); //1234
20
            for(int j=s.size()-1;j>=0;j--)
21
                s.push_back(s[j]);  //12344321
22
            long long n=stoll(s);
23
            n=n*n;
24
            if(n>r) break;
25
            if(n>=l && isPalindrome(n)) count++;
26
        }
27
        
28
        //odd
29
        for(int i=1;i<100000;i++)
30
        {
31
            string s=to_string(i); //1234
32
            for(int j=s.size()-2;j>=0;j--)
33
                s.push_back(s[j]);  //1234321
34
            long long n=stoll(s);
35
            //create palindrome of n
36
            n=n*n;
37
            if(n>r) break;
38
            if(n>=l && isPalindrome(n)) count++;
39
        }
40
          
41
        return count;
42
    }
43
};
