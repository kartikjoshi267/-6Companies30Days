class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q;
        for (auto i : senate){
            q.push(i);
        }
        
        int r = 0;
        int d = 0;
        while (!q.empty()){
            if (q.size() == r || q.size() == d){
                break;
            }
            
            char ch = q.front();
            q.pop();
            
            if (ch == 'D'){
                if (r != 0) r--;
                else{
                    d++;
                    q.push(ch);
                }
            }
            else if (ch == 'R'){
                if (d != 0) d--;
                else{
                    r++;
                    q.push(ch);
                }
            }
        }
        
        if (q.size() == r){
            return "Radiant";
        }
        
        return "Dire";
    }
};
