class Solution {
public:
    bool win(vector<string>&board,char c){
        for(int i=0;i<3;i++){
            if(board[i][0]==c && board[i][1]==c && board[i][2]==c)return true;
            if(board[0][i]==c && board[1][i]==c && board[2][i]==c)return true;
        }
        if(board[0][0]==c && board[1][1]==c && board[2][2]==c)return true;
        if(board[0][2]==c && board[1][1]==c && board[2][0]==c)return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int x=0,o=0;
        for(int i=0;i<3;i++){
            for(auto c:board[i]){
                if(c=='X')x++;
                else if(c=='O')o++;
            }
        }
        if(x!=o && x!=o+1)return false;
        if(win(board,'X') && x!=o+1)return false;
        if(win(board,'O') && x!=o)return false;
        return true;
    }
};