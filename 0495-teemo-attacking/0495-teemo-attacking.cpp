class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int n=t.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int inter=t[i+1]-t[i];
            cnt+=min(inter,d);
        }
        return cnt+d;
    }
};