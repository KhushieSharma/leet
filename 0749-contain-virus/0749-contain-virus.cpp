class clus{
    public:
    set<pair<int,int>>c;
    set<pair<int,int>>nc;
    int w=0;
};
class Solution {
public:
    void dfs(vector<vector<int>>&inf,int i,int j,vector<vector<bool>>&vis,clus &c1){
        if(i>=inf.size() || i<0 || j<0 || j>=inf[0].size() || vis[i][j] || inf[i][j]==-1)return;
        if(inf[i][j]==0){
            c1.w++;
            c1.nc.insert({i,j});
            return;
        }
        c1.c.insert({i,j});
        vis[i][j]=true;
        dfs(inf,i+1,j,vis,c1);
        dfs(inf,i,j+1,vis,c1);
        dfs(inf,i-1,j,vis,c1);
        dfs(inf,i,j-1,vis,c1);
    }
    int containVirus(vector<vector<int>>& inf) {
        int n=inf.size();
        int m=inf[0].size();
        int ans=0;
        while(1){
            vector<vector<bool>>vis(n,vector<bool>(m));
            auto cmp=[](const clus&a,const clus&b)
            {
                return a.nc.size()<b.nc.size();
            };
            priority_queue<clus,vector<clus>,decltype(cmp)>pq(cmp);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && inf[i][j]==1){
                        clus c;
                        dfs(inf,i,j,vis,c);
                        pq.push(c);
                    }
                }
            }
            if(pq.size()==0 || pq.top().nc.empty())break;
            clus k=pq.top(); pq.pop();
            for(auto x:k.c){
                inf[x.first][x.second]=-1;
            }
            ans+=k.w;
            while(!pq.empty()){
                clus k1=pq.top();
                pq.pop();
                for(auto x:k1.nc)inf[x.first][x.second]=1;
            }
        }
        return ans;

    }
};