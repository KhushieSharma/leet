class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int maxlen=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                cnt++;
                ans+=cnt;
            }
            else cnt=0;
        }
        return ans;
        // for(int i=0;i<n-2;i++){
        //         dif=nums[i+1]-nums[i];
        //         for(int j=i+2;j<n;j++){
        //             if(nums[j]-nums[j-1]==dif)
        //             cnt++;
        //             else break;
        //         }
        //     }
    }
};