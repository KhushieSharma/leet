class Solution {
public:
    int s(int ind,int t,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(t%coins[ind]==0)return t/coins[ind];
            else return 1e9;
        }
        if(dp[ind][t]!=-1)return dp[ind][t];
        int nt=s(ind-1,t,coins,dp);
        int tk=INT_MAX;
        if(coins[ind]<=t)tk=1+s(ind,t-coins[ind],coins,dp);
        return dp[ind][t]=min(nt,tk);
    }
    int coinChange(vector<int>& coins, int t) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        int ans=s(n-1,t,coins,dp);
        return(ans>=1e9)?-1:ans;
    }
};
