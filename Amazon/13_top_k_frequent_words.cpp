class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for (auto& w : words){
            m[w]++;
        }
        vector<string> v;
        while (k--){
            auto s = m.begin();
            int maxi = INT_MIN;
            for (auto it = m.begin(); it != m.end(); ++it){
                if (maxi < it->second && it->second != 0){
                    s = it;
                    maxi = it->second;
                }
            }
            v.push_back(s->first);
            m.erase(s);
        }
        return v;
    }
};
