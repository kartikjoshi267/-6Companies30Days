class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++){
            vector<int> temp(dist);
            for (int j = 0; j < edges.size(); j++){
                int s = edges[j][0];
                int d = edges[j][1];
                int wt = edges[j][2];
                if (dist[s] != INT_MAX){
                    temp[d] = min(dist[s] + wt, temp[d]);
                }

            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
