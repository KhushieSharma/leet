class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0;
        int l=0;
        int n=arr.size();
        int hi=k-1;
        int sum=0;
        for(int i=0;i<k;i++)sum+=arr[i];
        while(hi<n){
            if(sum>=threshold*k)cnt++;
            hi++;
            l++;
            if(hi<n){
                sum-=arr[l-1];
                sum+=arr[hi];
            }
        }
        return cnt;
    }
};