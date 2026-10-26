class Solution {
public:
    void dfs(long long &tot,int i,int j,vector<vector<int>>&grid, vector<vector<int>>&vis,int &k){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size(),vis[i][j] || grid[i][j] == 0)return;
        vis[i][j]=1;
        tot+=grid[i][j];
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(auto [dr,dc]:dir){
            int nr=i+dr;
            int nc=j+dc;
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]!=0)dfs(tot,nr,nc,grid,vis,k);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    long long tot=0;
                    dfs(tot,i,j,grid,vis,k);
                    if(tot%k==0)cnt++;
                    
                }
            }
        }
        return cnt;
    }
};