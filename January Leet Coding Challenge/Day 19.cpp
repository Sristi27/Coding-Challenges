Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),


1
class Solution {
2
public:
3
    string longestPalindrome(string s) {
4
        
5
        int n=s.size();
6
        if(n==0 || n==1)return s;
7
        
8
        bool mat[n][n];
9
        memset(mat,0,sizeof(mat));
10
        
11
        int start = 0;
12
        int res=0;
13
        string ans="";
14
        
15
        for (int i = 0; i < n; ++i)
16
        {
17
            mat[i][i] = 1;
18
            start=0;
19
            res=1;
20
        }
21
        
22
        for (int i = 0; i < n - 1; ++i) {
23
            if (s[i] == s[i + 1]) 
24
            {
25
                mat[i][i+1] = 1;
26
                start = i;
27
                res = 2;
28
            }
29
        }
30
        for(int len=3;len<=n;len++)
31
        {
32
            //for length=i
33
            for(int st=0;st<n-len+1;st++)
34
            {
35
                int end=st+len-1;
36
                if(s[st]==s[end] && mat[st+1][end-1]==1)
37
                    {
38
                        mat[st][end]=1;
39
                        if(len>res)
40
                        {
41
                            res=len;
42
                            start=st;
43
                        }
44
                    }
45
            }
46
        }
47
        cout<<res<<start;
48
        return s.substr(start,res);
49
    }
50
};
