class Solution {
public:
    int s(int ind, int buy, int cap,vector<int>&pri, vector<vector<vector<int>>>&dp){
        int n=pri.size();
        if(ind==n || cap==0)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy)return dp[ind][buy][cap]=max(-pri[ind]+s(ind+1,0,cap,pri,dp),s(ind+1,1,cap,pri,dp));
        return dp[ind][buy][cap]=max(pri[ind]+s(ind+1,1,cap-1,pri,dp),s(ind+1,0,cap,pri,dp));

    }
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        int cap=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        //dp[ind][buy/notbuy][cap 0 1 2]
        return s(0,1,cap,pri,dp);
    }
};