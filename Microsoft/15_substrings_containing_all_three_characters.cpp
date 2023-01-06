class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int l1 = -1, l2 = -1, l3 = -1;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'a') l1 = i;
            else if (s[i] == 'b') l2 = i;
            else if (s[i] == 'c') l3 = i;

            cnt += (1 + min(l1, min(l2, l3)));
        }
        return cnt;
    }
};
