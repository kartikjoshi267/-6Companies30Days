class Solution {
private:
    long long distance(vector<int>& p1, vector<int>& p2){
        return (long long)(pow(p1[0]-p2[0], 2)) + (long long) (pow(p1[1]-p2[1], 2));
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        set<vector<int>> spoints;
        vector<vector<int>> points = {p1,p2,p3,p4};
        for (int i = 0; i < 4; i++){
            spoints.insert(points[i]);
            for (int j = i+1; j < 4; j++){
                s.insert(distance(points[i], points[j]));
            }
        }

        if (s.size() != 2){
            return false;
        }

        if (spoints.size() != 4){
            return false;
        }

        // int diagonal, side;
        // // int 

        return true;
    }
};
