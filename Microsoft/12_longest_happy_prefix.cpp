class Solution {
public:
    string longestPrefix(string &s) {
        int n = s.length();
        if (n == 1){
            return "";
        }

        vector<int> kmp(n);
        kmp[0] = 0;
        int j = 0;
        int i = 1;
        while (i < n){
            if (s[i] != s[j] && j == 0){
                kmp[i] = 0;
                i++;
            } else if (s[i] == s[j]){
                kmp[i] = j+1;
                i++;
                j++;
            } else if (s[i] != s[j] && j != 0){
                j = kmp[j-1];
            }
        }

        return s.substr(0, kmp[n-1]);
    }
};
