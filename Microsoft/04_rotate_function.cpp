class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN;
        if (nums.size() == 1){
            return 0;
        }
        
        int init = 0;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            init += (i*nums[i]);
            sum += nums[i];
        }

        for (int i = 0; i < n; i++){
            sum -= nums[i];
            init = init - sum + nums[i]*(n-1);
            ans = max(ans, init);
            sum += nums[i];
        }
        return ans;
    }
};
