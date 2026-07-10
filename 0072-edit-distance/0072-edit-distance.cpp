class Solution {
public:
    int solve(int i,int j,string w1, string w2,vector<vector<int>>&dp){
        if(i<1)return j;
        if(j<1)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i-1]==w2[j-1])return dp[i][j]=solve(i-1,j-1,w1,w2,dp);
        return dp[i][j]=1+ min(solve(i,j-1,w1,w2,dp),min(solve(i-1,j-1,w1,w2,dp),solve(i-1,j,w1,w2,dp)));

    }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)dp[0][i]=i;
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
        return dp[n][m];
    }
};