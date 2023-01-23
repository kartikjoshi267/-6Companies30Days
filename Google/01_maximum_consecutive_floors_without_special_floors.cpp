class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = max(special[0]-bottom, top-special.back());
        int diff = INT_MIN;
        for (int i = 0; i < special.size()-1; i++){
            diff = max(special[i+1]-special[i]-1, diff);
        }
        return max(ans, diff);
    }
};
