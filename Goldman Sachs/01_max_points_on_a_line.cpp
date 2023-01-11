class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = INT_MIN;
        int n = points.size();
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int temp = 2;
                double delx = points[j][0] - points[i][0];
                double dely = points[j][1] - points[i][1];
                double m1 = dely/delx;
                
                for (int k = j + 1; k < n; k++){
                    double a = points[k][0] - points[i][0];
                    double b = points[k][1] - points[i][1];
                    double m2 = b/a;
                    if (m1 == m2)   temp++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
