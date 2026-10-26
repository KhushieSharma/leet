class Solution {
public:
    static bool cmp(string a,string b){
        return a.size()<b.size();
    }
    bool compare(string &s,string &t){
        int n=s.size();
        int m=t.size();
        if(m-n!=1)return false;
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i==n;
    }
    int sol(vector<string>&wor,int i,int prev,vector<vector<int>>&dp){
        if(i>=wor.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int t=0;
        if(prev==-1 || compare(wor[prev],wor[i]))t=1+sol(wor,i+1,i,dp);
        int nt=sol(wor,i+1,prev,dp);
        return dp[i][prev+1]=max(t,nt);
    }
    int longestStrChain(vector<string>& wor) {
        if(wor.size()==1)return 1;
        sort(wor.begin(),wor.end(),cmp);
        vector<vector<int>>dp(wor.size(),vector<int>(wor.size()+1,-1));
        return sol(wor,0,-1,dp);
    }
};