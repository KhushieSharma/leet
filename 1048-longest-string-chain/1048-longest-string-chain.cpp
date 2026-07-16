class Solution {
public:
    bool solve(string s1,string s2){
        if(s1.size()!=s2.size()+1)return false;
        int l=0, r=0;
        int n=s1.size(),m=s2.size();
        while(l<n){
            if(s1[l]==s2[r]){
                l++;
                r++;
            }
            else l++;
        }
        if(l==n && r==m)return true;
        return false;
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int n=arr.size();
        vector<int>dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(solve(arr[i],arr[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi)maxi=dp[i];
        }
        return maxi;
    }
};