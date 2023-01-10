class Solution {
vector<vector<int>> adj;
vector<int> par;
vector<int> dist;
void dfs(int node, int p = 0, int d = 0){
    par[node] = p;
    dist[node] = d;
    for (auto &u : adj[node]){
        if (u==p){
            continue;
        }
        dfs(u,node,d+1);
    }
}

int dfs2(int node, vector<int>& amount, int p = 0){
    int ret = amount[node];
    int mxc = INT_MIN;
    for (auto& u: adj[node]){
        if (u == p) continue;
        mxc = max(mxc, dfs2(u,amount,node));
    }

    if (mxc == INT_MIN) return ret;
    return mxc+ret;
}

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n, vector<int>());
        par.resize(n);
        dist.resize(n);

        for (auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0);
        int curr = bob;
        int bobDist = 0;
        while (curr != 0){
            if (dist[curr] > bobDist){
                amount[curr] = 0;
            } else if (dist[curr] == bobDist){
                amount[curr]/=2;
            }
            curr = par[curr];
            bobDist++;
        }

        return dfs2(0, amount);
    }
};
