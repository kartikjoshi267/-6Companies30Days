class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        sort(transactions.begin(), transactions.end());
        vector<pair<int, vector<string>>> v;
        map<string,int> m;
        int i = 0;
        for (auto &s : transactions){
            m[s]++;
            string t = s;
            vector<string> temp;
            size_t pos = 0;
            string delimiter = ",";
            while ((pos = t.find(delimiter)) != std::string::npos){
                temp.push_back(t.substr(0, pos));
                t.erase(0, pos+delimiter.size());
            }
            temp.push_back(t);
            v.push_back({i, temp});
            i++;
        }
        
        vector<string> ans;
        map<string,int> m2;
        for (auto &t : v){
            if (stoi(t.second[2]) > 1000){
                if (m2[transactions[t.first]] < m[transactions[t.first]]){
                    ans.push_back(transactions[t.first]);
                    m2[transactions[t.first]]++;
                }
            }
            for (auto &t2 : v){
                if (t.second[0] == t2.second[0] && abs(stoi(t2.second[1])-stoi(t.second[1])) <= 60 && t.second[3] != t2.second[3]){
                    if (m2[transactions[t2.first]] < m[transactions[t2.first]]){
                        ans.push_back(transactions[t2.first]);
                        m2[transactions[t2.first]]++;
                    }
                }
            }
        }
        return ans;
    }
};
