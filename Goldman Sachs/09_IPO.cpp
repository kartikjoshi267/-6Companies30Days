class Solution {
public:
    static bool cmp(pair<int , int> &a , pair<int , int>&b){
        return a.second < b.second;
    }
    
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>> v;
        for(int i = 0 ; i < p.size() ; i++){
            v.push_back({p[i],c[i]});
        }
        sort(v.begin(), v.end(), cmp);
        priority_queue<int> pq;
        int i = 0;
        int n = p.size();
		
        while(k--){
            while(i < n && v[i].second <= w){
                pq.push(v[i].first);
                i++;
            }
            if(!pq.empty()){
                int a = pq.top();
                w += a;
                pq.pop();
            }
        }
        return w;
		
    }
};
