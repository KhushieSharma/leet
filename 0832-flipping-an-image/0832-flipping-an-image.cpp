class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& img) {
        int n=img.size();
        vector<vector<int>>ans=img;
        for(int i=0;i<n;i++){
            reverse(ans[i].begin(),ans[i].end());
            for(int j=0;j<n;j++){
                if(ans[i][j]==1)ans[i][j]=0;
                else ans[i][j]=1;
            }
        }
        return ans;
    }
};