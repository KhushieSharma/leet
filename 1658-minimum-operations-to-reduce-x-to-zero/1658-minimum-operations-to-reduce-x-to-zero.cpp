class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int mini=-1;
        int tot=0;
        for(int x:nums)tot+=x;
        int tar=tot-x;
        if(tar<0)return -1;
        if(tar==0)return n;
        int l=0,sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>tar && l<=r){
                sum-=nums[l];
                l++;
            }
            if(sum==tar){
                mini=max(mini,r-l+1);
            }
        }
        if(mini==-1)return -1;
        return n-mini;
    }
};