class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp,vector<vector<int>>& vis){
        vis[i][j]=1;
        int temp=0;
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(auto [dr,dc]:dir){
            int nr=i+dr;
            int nc=j+dc;
            if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() ){
                if(mat[nr][nc]>mat[i][j]){
                    if(vis[nr][nc])temp=max(temp,dp[nr][nc]);
                    else{
                        dp[nr][nc]=dfs(nr,nc,mat,dp,vis);
                        temp=max(temp,dp[nr][nc]);
                    }
                }
            }
        }
        return temp+1;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1));
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])dp[i][j]=dfs(i,j,mat,dp,vis);
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};