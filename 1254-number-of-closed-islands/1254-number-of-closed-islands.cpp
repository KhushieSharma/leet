class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m)return false;
        if (grid[r][c] == 1 || vis[r][c])return true;
        vis[r][c]=1;
        vector<pair<int,int>>adj={{-1,0},{0,1},{1,0},{0,-1}};
        bool close=true;
        for(auto [dr,dc]:adj){
            int nr=r+dr;
            int nc=c+dc;
            if(!dfs(nr,nc,vis,grid))close=false;
        }
        return close;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(dfs(i,j,vis,grid))cnt++;
                }
            }
        }
        return cnt;
    }
};