class Solution {
private:
    long long mod = 1e9+7;
    long long _reverse(int num){
        int rev = 0;
        do {
            int rem = num%10;
            rev = rev*10 + rem;
            num/=10;
        } while (num != 0);

        return rev;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        vector<int> rev(n);
        for (int i = 0; i < n; i++){
            rev[i] = _reverse(nums[i]);
        }
        for (int i = 0; i < n; i++){
            rev[i] = rev[i] - nums[i];
        }
        map<int, long long> m;
        for (int i = 0; i < n; i++){
            m[rev[i]]++;
        }
        for (auto it : m){
            // cout << it.first << "\t" << it.second << endl;
            if (it.second > 1){
                cnt += ((it.second-1)*(it.second)/2)%mod;
            }
        }
        return cnt%mod;
    }
};
