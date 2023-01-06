class Solution {
private:
    bool isValid(vector<int> output, int n){
        int s = 0;
        for (auto& i : output){
            s += i;
        }
        return s == n;
    }

    void solve(int k, int index, vector<vector<int>>& ans, vector<int> output, vector<int> &nums, int n){
        
        if (output.size() == k && isValid(output, n)){
            ans.push_back(output);
            return;
        }

        // if (output.size() < k){
            for (int i = index; i < nums.size() && output.size() < k; i++){
                if (accumulate(output.begin(), output.end(), 0) < n){
                    output.push_back(nums[i]);
                    solve(k, i+1, ans, output, nums, n);
                    output.pop_back();
                }
            }
        // }

        return;
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k >= n){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> output;
        vector<int> nums;
        for (int i = 1; i <= 9; i++){
            nums.push_back(i);
        }
        solve(k, 0, ans, output, nums, n);
        return ans;
    }
};
