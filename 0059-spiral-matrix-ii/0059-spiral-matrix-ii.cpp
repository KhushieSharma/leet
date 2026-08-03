class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)return {};
        vector<vector<int>>mat(n,vector<int>(n,0));
        int l=0,r=n-1,top=0,bot=n-1,num=1;
        while(l<=r && top<=bot){
            for(int i=l;i<=r;i++){
                mat[top][i]=num++;
            }
            top++;
            for(int i=top;i<=bot;i++){
                mat[i][r]=num++;
            }
            r--;
            if(top<=bot){
            for(int i=r;i>=l;i--)mat[bot][i]=num++;
            bot--;
            }
            if(r>=l){
            for(int i=bot;i>=top;i--)mat[i][l]=num++;
            l++;
            }
        }
        return mat;
    }
};