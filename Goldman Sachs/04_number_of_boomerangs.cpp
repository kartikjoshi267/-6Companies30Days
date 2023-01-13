class Solution {
private:
    long long distance(vector<int> &a, vector<int> &b){
        return pow((long long) (b[0]-a[0]), 2)+pow((long long) (b[1]-a[1]), 2);
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        // cout << n << endl;
        if (n <= 2) return 0;
        int cnt = 0;
        map<pair<int,int>, set<int>> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (points[i] != points[j]){
                    int dist = distance(points[i], points[j]);
                    m[{i,dist}].insert(j);
                }
            }
        }
        
        for (auto& pr : m){
            int s = pr.second.size();
            cnt += s*(s-1);
        }

        return cnt;
    }
};
