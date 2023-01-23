class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int r = i-k < 0 ? 0 : i-k; r <= i+k && r < n; r++){
                    for (int c = j-k < 0 ? 0 : j-k; c <= j+k && c < m; c++){
                        ans[i][j] += mat[r][c];
                    }
                }
            }
        }
        return ans;
    }
};
