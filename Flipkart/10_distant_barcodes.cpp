class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        map<int,int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for (int i = 0; i < n; i++){
            m[barcodes[i]]++;
        }
        for (auto &i : m){
            pq.push({i.second,i.first});
        }

        vector<int> ans;
        for (int i = 0; i < n; i++){
            auto it = pq.top();
            if (ans.empty()){
                ans.push_back(it.second);
                pq.pop();
                pq.push({it.first-1,it.second});
            } else {
                if (ans[i-1] != it.second){
                    ans.push_back(it.second);
                    pq.pop();
                    pq.push({it.first-1,it.second});
                } else {
                    pq.pop();
                    auto it2 = pq.top();
                    pq.pop();
                    ans.push_back(it2.second);
                    pq.push({it.first,it.second});
                    pq.push({it2.first-1,it2.second});
                }
            }
        }
        return ans;
    }
};
