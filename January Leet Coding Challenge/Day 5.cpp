Longest Substring Without Repeating Characters.
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.







1
class Solution {
2
public:
3
    int lengthOfLongestSubstring(string s) {
4
        //abcabcbb
5
        unordered_map<char,int>mp;
6
        int left=0,right=0,len=0;
7
        int n=s.size();
8
        while(right<n)
9
        {
10
            //already in set
11
            //increase left
12
            if(mp.find(s[right])!=mp.end())
13
            {
14
                left=max(left,mp[s[right]]+1);
15
                mp[s[right]]=right;
16
            }
17
            
18
            else mp.insert({s[right],right});
19
            len=max(len,right-left+1);
20
            right++;
21
        }
22
        return len;
23
    }
24
};
