class Solution {
public:
    int f(vector<int>&arr,int tar,int ind,vector<vector<int>>&dp){
        if(ind==0){
            if(tar%arr[ind]==0)return 1;
            else return 0;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int nt=f(arr,tar,ind-1,dp);
        int t=0;
        if(arr[ind]<=tar)t=f(arr,tar-arr[ind],ind,dp);
        return dp[ind][tar]=t+nt;
    }
    int change(int tar, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(arr,tar,n-1,dp);
    }
};