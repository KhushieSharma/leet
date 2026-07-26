class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans=1;
        if(nums.size()==3){
            for(int i=0;i<nums.size();i++)ans*=nums[i];
            return ans;
        }
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int pos=nums[n-1]*nums[n-2]*nums[n-3];
        int pos2=nums[0]*nums[1]*nums[n-1];
        return max(pos,pos2);
    }
};