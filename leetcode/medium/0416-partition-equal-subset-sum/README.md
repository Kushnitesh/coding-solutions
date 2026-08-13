# Partition Equal Subset Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums`, return `true`  *if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or* `false` *otherwise*.

 

 **Example 1:** 

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

```

 **Example 2:** 

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

```

 

 **Constraints:** 

- 1 <= nums.length <= 200
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 55 ms (beats 92.48%)  
**Memory:** 110.6 MB (beats 33.50%)  
**Submitted:** 2026-08-13T09:54:35.292Z  

```cpp
class Solution {
public:
    bool solve(int i ,vector<int>&arr,int target,int n,vector<vector<int>>&dp)
    {
        if(target==0)   return true;
        if(i==n||target<0)  return false;
        if(dp[i][target] !=-1)  return dp[i][target];
        return dp[i][target]=solve(i+1,arr,target-arr[i],n,dp)||solve(i+1,arr,target,n,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum +=nums[i];
        }
        if(sum % 2!=0)
        {
            //if sum is odd -> not possible to make equal oppurtinities
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return solve(0, nums,target,n,dp);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/partition-equal-subset-sum/)