class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1 && grid[0][0]==1)return 4;
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<int>>nei(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(auto[dr,dc]:dir){
                        int nr=i+dr;
                        int nc=j+dc;
                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)nei[i][j]++;
                    }
                }
            }
        }
        int tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)tot+=4-nei[i][j];
            }
        }
        return tot;
    }
};