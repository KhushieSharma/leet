class Solution {
public:
    bool coun(int mid,vector<int>&nums,int k){
        int sub=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                sub++;
                sum=nums[i];
                if(sub>k)return false;
            }
            else{
                sum+=nums[i];
            } 
            
        }
        return sub<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(coun(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};