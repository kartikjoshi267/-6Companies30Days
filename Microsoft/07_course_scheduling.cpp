class Solution {
private:
    vector<bool> vis;
    vector<bool> pathvis;
    
    bool dfs(map<int,vector<int>> &g, int i){
        if (pathvis[i]){
            return true;
        }
        
        vis[i] = true;
        pathvis[i] = true;
        for (int j = 0; j < g[i].size(); j++){
            if (!vis[g[i][j]]){
                if (dfs(g, g[i][j])){
                    return true;
                }
            } else if (pathvis[g[i][j]]){
                return true;
            }
        }
        pathvis[i] = false;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        if (n == 1 || (n == 2 && arr.size() <= 1))  return true;
        map<int, vector<int>> g;
        for (int i = 0; i < arr.size(); i++){
            g[arr[i][0]].push_back(arr[i][1]);
        }
        
        vis.resize(n, false);
        pathvis.resize(n, false);
        bool f = false;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                if (dfs(g, i)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
