class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> v(n, vector<int>(n,INT_MAX));
        for (auto &e : edges){
            v[e[0]][e[1]] = e[2];
            v[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i == j){
                        v[i][j] = 0;
                        continue;
                    }
                    if (v[i][k] == INT_MAX || v[k][j] == INT_MAX){
                        continue;
                    }
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int mini = 0;
        int minCnt = INT_MAX;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (i != j && v[i][j] <= dt){
                    cnt++;
                }
            }
            if (cnt < minCnt){
                minCnt = cnt;
                mini = i;
            } else if (cnt == minCnt){
                mini = i;
            }
        }

        return mini;
    }
};
