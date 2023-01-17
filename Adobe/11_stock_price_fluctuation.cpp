class StockPrice {
    map<int,int> m;
    set<pair<int,int>> s;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (m[timestamp] == 0){
            m[timestamp] = price;
            s.insert({price,timestamp});
        } else {
            s.erase(s.find({m[timestamp],timestamp}));
            s.insert({price,timestamp});
            m[timestamp] = price;
        }
    }
    
    int current() {
        auto it = --m.end();
        return it->second;
    }
    
    int maximum() {
        auto it = --s.end();
        return it->first;
    }
    
    int minimum() {
        return (s.begin())->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
