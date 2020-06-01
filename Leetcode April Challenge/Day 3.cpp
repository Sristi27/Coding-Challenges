Question: Given an integer array nums, find the contiguous subarray (containing at least one number) which has 
the largest sum and return its sum.

//C++ soln

class Solution {
    int getCrossSum(vector<int> &nums,int low,int high)
    {
        if(low >=high)
            return nums[low];
        int mid = low+high;
        mid =mid/2;
        int sum = nums[mid];
        int tsum=sum;
        for(int i = mid-1;i>=low;i--)
        {
            tsum+=nums[i];
            if(sum<tsum)
                sum=tsum;
        }
        tsum=sum;
        for(int i = mid+1; i<=high; i++)
        {
            tsum+=nums[i];
            if(sum<tsum)
                sum=tsum;
        }
        return sum;
    }
    int maxSum(vector<int> &nums,int low, int high) {
        if(low>=high)
            return nums[low];
        int mid = low+high;
        mid = mid/2;
        int crossSum = getCrossSum(nums,low,high);
        int leftSum = maxSum(nums,low,mid);
        int rightSum = maxSum(nums,mid+1,high);
        if(leftSum> rightSum && leftSum> crossSum)
            return leftSum; 
        if(rightSum> crossSum)
            return rightSum;
        return crossSum;
    }
public:
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums,0,nums.size()-1);
    }
    
};
