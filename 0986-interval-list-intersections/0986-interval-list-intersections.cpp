class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fir, vector<vector<int>>& sec) {
        vector<vector<int>>res;
        int i=0,j=0;
        while(i<fir.size() && j<sec.size()){
            int lo=max(fir[i][0],sec[j][0]);
            int hi=min(fir[i][1],sec[j][1]);
            if(lo<=hi)res.push_back({lo,hi});
            if(fir[i][1]<sec[j][1])i++;
            else j++;
        }
        return res;

    }
};