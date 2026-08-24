class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c){
        if(r<0 || c<0 ||r>=board.size() || c>=board[0].size() || board[r][c]!='E')return;
        int cnt=0;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
        for(auto[dr,dc]:dir){
            int nr=dr+r;
            int nc=dc+c;
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size()){
                if(board[nr][nc]=='M')cnt++;
            }
        }
        if(cnt>0)board[r][c]=cnt+'0';
        else{
            board[r][c]='B';
            for(auto[dr,dc]:dir){
                int nr=r+dr;
                int nc=c+dc;
                dfs(board,nr,nc);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n=board.size(), m=board[0].size();
        int r=click[0], c=click[1];
        if(board[r][c]=='M')board[r][c]='X';
        else dfs(board,r,c);
        return board;
    }
};