Question: Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Python Soln

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        c=nums.count(0)
        i=0
        length=len(nums)
        if c!=length:
                while(i<length):
                    if(nums[i]==0):
                        nums.remove(0)
                        length = length -1  
                        continue
                    i = i+1
                print(nums)
                for i in range(c):
                    nums.append(0)
