class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        int indmin=-1,indmax=-1;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            if(nums[i]==mini)indmin=i;
            maxi=max(maxi,nums[i]);
            if(nums[i]==maxi)indmax=i;
        }
        int left=min(indmin,indmax);
        int right=max(indmin,indmax);
        int front=right+1;
        int back=n-left;
        int frontback=(left+1)+(n-right);
        return min({front,back,frontback});
    }
};