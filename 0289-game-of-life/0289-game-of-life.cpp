class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto[dr,dc]:dir){
                    int nr=dr+i;
                    int nc=j+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==1)v[i][j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1 && v[i][j]<2)board[i][j]=0;
                else if(board[i][j]==1 && v[i][j]>=2 && v[i][j]<=3)board[i][j]=1;
                else if(board[i][j]==1 && v[i][j]>3)board[i][j]=0;
                else if(board[i][j]==0 && v[i][j]==3)board[i][j]=1;
            }
        }
    }
};