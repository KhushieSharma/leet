class Solution {
public:
    int hIndex(vector<int>& cit) {
     int n=cit.size();
     int l=1;
     int h=n;
     int ans=0;
     while(l<=h){
        int mid=l+(h-l)/2;
        if(cit[n-mid]>=mid){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
     }
     return ans;
    }
};