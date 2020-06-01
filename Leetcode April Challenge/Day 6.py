Question: Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

//Python soln

from collections import defaultdict 
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        temp = defaultdict(list) 
        for ele in strs: 
            temp[str(sorted(ele))].append(ele) 
        res = list(temp.values()) 
        return res
