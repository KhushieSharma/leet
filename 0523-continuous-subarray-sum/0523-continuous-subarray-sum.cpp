class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int>mp;
        mp[0]=-1;
        int sum=0;
        int n=nums.size();
        if(n<=1)return false;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2)return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};