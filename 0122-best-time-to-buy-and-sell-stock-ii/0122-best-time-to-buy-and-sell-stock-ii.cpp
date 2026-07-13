class Solution {
public:
    int s(int ind, int buy, vector<int>&pri,int n, vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy)
        profit=max(-pri[ind]+s(ind+1,0,pri,n,dp), 0+s(ind+1,1,pri,n,dp));
        else profit=max(pri[ind]+s(ind+1,1,pri,n,dp),0+s(ind+1,0,pri,n,dp));
        return dp[ind][buy]=profit;

    }
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return s(0,1,pri,n,dp);
    }
};