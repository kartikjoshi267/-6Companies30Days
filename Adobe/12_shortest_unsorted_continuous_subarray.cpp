class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = -1;
        int j = -1;
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        for (int k = 0; k < nums.size(); k++){
            if (nums[k] != copy[k]){
                i = k;
            }
        }
        
        for (int k = nums.size()-1; k >= 0; k--){
            if (nums[k] != copy[k]){
                j = k;
            }
        }
        
        if (i == -1 && j == -1){
            return 0;
        }
        
        return i-j+1;
    }
};
