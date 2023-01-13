class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        map<int, set<int>> m;
        for (int i = 0; i < n; i++){
            m[cards[i]].insert(i);
        }
        
        bool f = false;
        for (int i = 0; i < n; i++){
            if (m[cards[i]].size() > 1){
                f = true;
                break;
            }
        }
        if (!f)
            return -1;
        int ans = INT_MAX;
        
        for (auto &pr : m){
            auto s = pr.second;
            for (auto it = s.begin(); it != --s.end(); ++it){
                auto t = it;
                ++t;
                ans = min(ans, (*t)-(*it)+1);
            }
        }
        return ans;
    }
};
