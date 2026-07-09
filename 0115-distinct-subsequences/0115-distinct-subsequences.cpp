class Solution {
public:
    int f(int i,int j,string s, string t,vector<vector<int>>&dp){
        if(j<1)return 1; //found 
        if(i<1)return 0;    //not found
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]=f(i-1,j,s,t,dp)+f(i-1,j-1,s,t,dp);
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1; //nothing in t
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
               else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};