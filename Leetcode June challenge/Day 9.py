class Solution:
    def find(self,string1,string2,m,n):
        if m == 0:    
            return True
        if n == 0:    
            return False
        if string1[m-1] == string2[n-1]: 
            return self.find(string1, string2, m-1, n-1) 
        return self.find(string1, string2, m, n-1) 
    
    
    def isSubsequence(self, s: str, t: str) -> bool:
        m=len(s)
        n=len(t)
        if self.find(s,t,m,n)==1:
            return True
        else:
            return False
