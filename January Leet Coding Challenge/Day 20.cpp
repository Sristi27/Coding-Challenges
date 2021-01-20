<h1>Valid Parentheses</h1>
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
   Show Hint #1  
   Show Hint #2  
   Show Hint #3  
C++	
1
class Solution {
2
public:
3
    bool isValid(string s) {
4
        stack<int>st;
5
        for(int i=0;s[i]!='\0';i++)
6
        {
7
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
8
            {
9
                st.push(s[i]);
10
                continue;
11
            }
12
            if(st.empty()) return false;
13
                
14
            if(!st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']'))
15
            {
16
                char open=st.top();
17
                cout<<open<<endl;
18
                st.pop();
19
                if(s[i]==')' && open!='(') return false;
20
                if(s[i]=='}' && open!='{') return false;
21
                if(s[i]==']' && open!='[') return false;
22
            }
23
        }
24
        
25
        return st.empty();
26
        
27
    }
28
};
