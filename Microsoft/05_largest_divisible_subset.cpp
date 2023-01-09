class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) return nums;
        
        vector<int> dp(n, 1);
        vector<int> hash(n), ans;
        
        int maxLen = 1;
        int lastIdx = 0;
        
        for (int i = 1; i < n; i++){
            hash[i] = i;
            for (int j = 0; j < i; j++){
                if (nums[i]%nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxLen){
                maxLen = dp[i];
                lastIdx = i;
            }
        }
        
        ans.push_back(nums[lastIdx]);
        while (hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        
        return ans;
    }
};
