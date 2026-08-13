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