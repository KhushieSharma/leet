class Solution {
public:
    // void dfs(int node,vector<int>&path,vector<vector<int>>& ans,vector<vector<int>>& graph){
    //     path.push_back(node);
    //     if(node==graph.size()-1)ans.push_back(path);
    //     else{
    //         for(auto nei:graph[node]){
    //             dfs(nei,path,ans,graph);
    //         }
    //     }
    //     path.pop_back();
    // }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        queue<vector<int>>q;
        vector<int>path;
        q.push({0});
        while(!q.empty()){
            path=q.front();
            q.pop();
            if(path.back()==n-1){ans.push_back(path);}
            for(auto it:graph[path.back()]){
                vector<int>temp=path;
                temp.push_back(it);
                q.push(temp);
            }
        }
        return ans;
        // vector<int>path;
        // dfs(0,path,ans,graph);
        // return ans;
    }
};