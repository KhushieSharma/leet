class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cnt+=maxi-nums[i];
        }
        return cnt;
    }
};