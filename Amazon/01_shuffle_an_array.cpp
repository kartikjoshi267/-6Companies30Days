class Solution {
    vector<int> org, random;
public:
    Solution(vector<int>& nums) {
        org = nums;
        random = nums;
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        next_permutation(random.begin(), random.end());
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
