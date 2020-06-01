Question: Given a non-empty array of integers, every element appears twice except for one. Find that single one.

//Python Soln


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        for i in nums:
            if nums.count(i)==1:
                return i
