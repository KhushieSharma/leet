class Solution {
public:
    int sol(int i,int j,vector<int>&nums,vector<int>&dp){
        if(j==i)return nums[i];
        if(j<i)return 0;
        if(dp[j]!=-1)return dp[j];
        int l=sol(i,j-1,nums,dp);
        int r=nums[j]+sol(i,j-2,nums,dp);
        return dp[j]=max(l,r);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int a=sol(1,n-1,nums,dp1);
        int b=sol(0,n-2,nums,dp2);
        return max(a,b);
    }
};