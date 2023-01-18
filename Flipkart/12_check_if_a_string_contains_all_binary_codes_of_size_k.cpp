class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> m;
        for (int i = 0; i < s.length(); i++){
            m.insert(s.substr(i,k));
        }

        int cnt = 0;
        for (auto& i : m){
            if (i.length() == k){
                // cout << i.first << " " << i.second << endl;
                cnt++;
            }
        }

        return cnt == pow(2,k);
    }
};
