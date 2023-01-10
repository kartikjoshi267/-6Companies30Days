class Solution {
private:
    long long solve(vector<int> & nums, int diff, int s, int e){
        if (s >= e){
            return 0;
        }

        int mid = (s+e)/2;
        long long result = solve(nums, diff, s, mid) + solve(nums, diff, mid+1, e);
        int s1 = s, e1 = mid, s2 = mid+1, e2 = e;
        vector<long long> merged;

        for (int j = s2; j <= e2; j++){
            int req = nums[j] + diff;
            int ind = upper_bound(nums.begin()+s1, nums.begin()+e1+1, req) - nums.begin() - 1;
            if (ind <= e1){
                result += (ind-s1+1);
            }
        }

        while (s1 <= e1 && s2 <= e2){
            if (nums[s1] <= nums[s2]){
                merged.push_back(nums[s1++]);
            } else {
                merged.push_back(nums[s2++]);
            }
        }

        while (s1 <= e1){
            merged.push_back(nums[s1++]);
        }

        while (s2 <= e2){
            merged.push_back(nums[s2++]);
        }

        for (int j = s; j <= e; j++){
            nums[j] = merged[j-s];
        }

        return result;
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++){
            nums[i] = nums1[i] - nums2[i];
        }

        return solve(nums, diff, 0, n-1);
    }
};
