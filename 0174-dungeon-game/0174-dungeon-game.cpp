class Solution {
public:
    int solve(int i,int j, vector<vector<int>>&dun,vector<vector<int>>&dp){
        int n=dun.size();
        int m=dun[0].size();   
        if(i>=n || j>=m)return 1e9;
        if(i==n-1 && j==m-1)return max(1,1-dun[i][j]);
        if(dp[i][j]!=-1)return dp[i][j];
        int l=solve(i,j+1,dun,dp);
        int r=solve(i+1,j,dun,dp);
        int need=min(l,r);
        return dp[i][j]=max(1,need-dun[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n=dun.size();
        int m=dun[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,dun,dp);
    }
};