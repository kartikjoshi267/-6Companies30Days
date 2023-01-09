class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> set;
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        
        long long area = 0;
        
        for (auto& rect : rectangles){
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);
            
            area += ((long long)(rect[3]-rect[1]))*((long long)(rect[2]-rect[0]));
            
            string s1 = to_string(rect[0]) + "," + to_string(rect[1]);
            string s2 = to_string(rect[0]) + "," + to_string(rect[3]);
            string s3 = to_string(rect[2]) + "," + to_string(rect[3]);
            string s4 = to_string(rect[2]) + "," + to_string(rect[1]);
            
            if (set.find(s1) != set.end()){
                set.erase(s1);
            } else {
                set.insert(s1);
            }
            
            if (set.find(s2) != set.end()){
                set.erase(s2);
            } else {
                set.insert(s2);
            }
            
            if (set.find(s3) != set.end()){
                set.erase(s3);
            } else {
                set.insert(s3);
            }
            
            if (set.find(s4) != set.end()){
                set.erase(s4);
            } else {
                set.insert(s4);
            }
        }
        
        if (set.find(to_string(x1) + "," + to_string(y1)) == set.end() || set.find(to_string(x1) + "," + to_string(y2)) == set.end() || set.find(to_string(x2) + "," + to_string(y1)) == set.end() || set.find(to_string(x2) + "," + to_string(y2)) == set.end() || set.size() != 4)
            return false;
        
        return area == ((long long)(x2-x1))*((long long)(y2-y1));
    }
};
