class Solution {
public:
    bool ispal(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j)return true;
        if(s[i]!=s[j])return false;
        if(dp[i][j]!=-1)return dp[i][j];
        return ispal(s,i+1,j-1,dp);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(s,i,j,dp) && (j-i+1>r-l+1)){
                    l=i;
                    r=j;
                }
            }
        }
        return s.substr(l,r-l+1);
    }
};