class Solution {
private:
    vector<vector<string>> v;
    bool isOk(string str, int start, int end){
        string s = str.substr(start, end-start+1);
        bool f = (str[start] == '0' ? false : true);
        if (!f){
            for (int i = start+1; i <= end; i++){
                if (str[i] != '0'){
                    return false;
                }
            }

            if (s.length() > 1) return false;
        }

        if (stoll(s) > 255){
            return false;
        }
        return true;
    }

    void solve(string s, vector<string> out, int index=0){
        if (index == s.length() && out.size() == 4){
            v.push_back(out);
            return;
        }

        for (int i = index; i < s.length(); i++){
            if (isOk(s, index, i)){
                out.push_back(s.substr(index, i-index+1));
                solve(s, out, i+1);
                out.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(s, vector<string>(0));
        for (auto vstr : v){
            string str = "";
            for (auto c : vstr){
                str += (c+'.');
            }
            str.pop_back();
            ans.push_back(str);
        }
        return ans;
    }
};
