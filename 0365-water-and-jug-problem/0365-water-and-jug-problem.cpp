class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int z=x+y;
        vector<int>s={x,-x,y,-y};
        queue<int>q;
        vector<int>vis(z+1,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            if(n==target)return true;
            for(int i=0;i<4;i++){
                int nr=n+s[i];
                if(nr>=0 && nr<=z && vis[nr]==0){
                    q.push(nr);
                    vis[nr]=1;
                }
            }
        }
        return false;
    }
};