class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(n,0));
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(auto [rr,cc]:dir){
                int nr=rr+r;
                int nc=cc+c;
                if(nr>=0 && nc>=0 && nr<n &&nc<m && !vis[nr][nc]){
                    dis[nr][nc]=dis[r][c]+1;
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<bool>>vis1(n,vector<bool>(m,false));
        pq.push({dis[0][0],{0,0}});
        while(!pq.empty()){
            auto pr=pq.top();
            pq.pop();
            int d=pr.first;
            int r=pr.second.first;
            int c=pr.second.second;
            if(vis1[r][c]) continue;
            vis1[r][c]=true;
            if(r==n-1 && c==m-1)return d;
            for(auto [dr,dc]:dir){
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis1[nr][nc]){
                    int news=min(d,dis[nr][nc]);
                    pq.push({news,{nr,nc}});
                }
            }
        }
    return 0;
    }
};