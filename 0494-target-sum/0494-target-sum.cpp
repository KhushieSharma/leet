class Solution {
public:
    int f(int ind, vector<int>&nums,int tar,vector<vector<int>>&dp){
        if(ind==0){
            if(tar==0 && nums[0]==0) return 2;
            if(tar==0 || nums[0]==tar) return 1;
        return 0;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int nott=f(ind-1,nums,tar,dp);
        int take=0;
        if(nums[ind]<=tar)
        take=f(ind-1,nums,tar-nums[ind],dp);
        return dp[ind][tar]=take+nott;
    }
    int Partition(vector<int>& nums,int d) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum-d<0 || (sum-d)%2!=0)return 0;
        vector<vector<int>>dp(n,vector<int>((sum-d)/2 +1,-1));
        return f(n-1,nums,(sum-d)/2,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return Partition(nums,target);
    }
};