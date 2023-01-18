class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        string order_new = "";
        for (char c : s){
            m[c]++;
        }
        for (char c : order){
            if (m[c] != 0)  order_new += c;
        }

        int i = 0;
        string ans = "";
        for (auto c : order_new){
            while (m[c] != 0){
                ans += c;
                i++;
                m[c]--;
            }
        }

        for (auto i : m){
            int a = i.second;
            while (a != 0){
                ans += i.first;
                a--;
            }
        }
        return ans;
    }
};
