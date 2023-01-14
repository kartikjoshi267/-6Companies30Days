class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return false;
        map<int, int> fm, hm;
        for (auto num : nums){
            fm[num]++;
        }
        
        for (int i = 0; i < n; i++){
            int j = nums[i];
            if (fm[j] == 0) continue;
            if (hm[j] > 0){
                fm[j]--;
                hm[j]--;
                hm[j+1]++;
            } else {
                if (fm[j] && fm[j+1] && fm[j+2]){
                    fm[j]--;
                    fm[j+1]--;
                    fm[j+2]--;
                    hm[j+3]++;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
