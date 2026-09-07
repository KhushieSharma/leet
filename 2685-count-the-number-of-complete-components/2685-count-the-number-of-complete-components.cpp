class Solution {
public:

    class DisjointSet {
        vector<int> rank, parent, size;

    public:

        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v) return;

            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v) return;

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }

        int sizep(int u) {
            return size[findUPar(u)];
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet d(n);
        vector<int> deg(n, 0);
        for (auto it : edges) {
            d.unionBySize(it[0], it[1]);
            deg[it[0]]++;
            deg[it[1]]++;
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[d.findUPar(i)].push_back(i);
        }
        int ans = mp.size();
        for (auto it : mp) {
            int sz = d.sizep(it.first);
            bool com = true;
            for (int node : it.second) {
                if (deg[node] != sz - 1) {
                    com = false;
                    break;
                }
            }
            if (!com)
                ans--;
        }
        return ans;
    }
};