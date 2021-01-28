Determine if Two Strings Are Close.

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
Example 4:

Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
   Hide Hint #1  
Operation 1 allows you to freely reorder the string.
   Show Hint #2  
C++	
1
class Solution {
2
public:
3
    bool closeStrings(string word1, string word2) {
4
        if(word1.size()!=word2.size()) return false;
5
        
6
        vector<int>freq1(26,0);
7
        vector<int>freq2(26,0);
8
        
9
        for(char c:word1) 
10
            freq1[c-'a']++;
11
        
12
        for(char c:word2) 
13
            freq2[c-'a']++;
14
        
15
        for(int i=0;i<26;i++)
16
        {
17
            if((freq1[i]==0 && freq2[i]!=0)||freq2[i]==0 && freq1[i]!=0) return false;
18
            
19
        }  
20
        
21
        sort(freq1.begin(),freq1.end());
22
        sort(freq2.begin(),freq2.end());
23
        return freq1==freq2;
24
    }
25
        
26
};
