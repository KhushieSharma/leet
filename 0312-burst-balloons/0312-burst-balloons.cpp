class Solution {
public:
    int sol(int i,int j, vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost=nums[i-1]*nums[ind]*nums[j+1]+sol(i,ind-1,nums,dp)+sol(ind+1,j,nums,dp);
            maxi=max(cost,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return sol(1,n,nums,dp);
    }
};