class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),lis(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    lis[i]=lis[j];
                }
                else if(nums[i]>nums[j] && 1+dp[j]==dp[i])lis[i]+=lis[j];
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)ans+=lis[i];
        }
        return ans;
    }
};