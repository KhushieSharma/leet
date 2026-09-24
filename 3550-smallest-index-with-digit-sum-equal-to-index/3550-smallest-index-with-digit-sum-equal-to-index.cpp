class Solution {
public:
    int digi(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            if(digi(nums[i])==i)return i;
        }
        return -1;
    }
};