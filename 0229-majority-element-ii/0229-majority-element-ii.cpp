class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int t=n/3;
        int c1=0,c2=1,v1=0,v2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==c1)v1++;
            else if(nums[i]==c2)v2++;
            else if(v1==0){
                c1=nums[i];
                v1=1;
            }
            else if(v2==0){
                c2=nums[i];
                v2=1;
            }
            else{
                v1--;
                v2--;
            }
        }
        int f1=0,f2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==c1)f1++;
            if(nums[i]==c2)f2++;
        }
        vector<int>ans;
        if(f1>t)ans.push_back(c1);
        if(f2>t)ans.push_back(c2);
        return ans;
        
        
        
        
                // unordered_map<int,int>mpp;
        // for(int i=0;i<n;i++)mpp[nums[i]]++;
        // int c=n/3;
        // vector<int>ans;
        // for(auto it: mpp){
        //     if(it.second>c)ans.push_back(it.first);
        // }
        // return ans;
    }
};