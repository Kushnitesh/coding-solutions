class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(target>nums[mid])
            {
                l=mid+1;
            }
            if(target<nums[mid])
            {
                h=mid-1;
            }
        }
        return -1;
    }
};