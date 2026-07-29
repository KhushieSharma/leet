class Solution {
public:
    int countBattleships(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'X' && !vis[i][j]) {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()) {
                        auto [r,c] = q.front();
                        q.pop();
                        for(auto [dr,dc] : dir) {
                            int nr = r + dr;
                            int nc = c + dc;
                            if(nr>=0 && nr<n && nc>=0 && nc<m &&
                               mat[nr][nc]=='X' && !vis[nr][nc]) {

                                vis[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
            }
};