class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int total = 0;
        map<char, int> m1;
        for (int i = 0; i < n; i++){
            m1[secret[i]]++;;
        }

        map<char, int> m2;
        for (int i = 0; i < n; i++){
            m2[guess[i]]++;
        }

        for (auto pr : m1){
            total+=min(pr.second, m2[pr.first]);
        }

        int bulls = 0;
        for (int i = 0; i < n; i++){
            if (secret[i] == guess[i]){
                bulls++;
            }
        }

        string ans = "";
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(total-bulls);
        ans += "B";

        return ans;
    }
};
