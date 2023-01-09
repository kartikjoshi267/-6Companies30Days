class Solution {
private:
    int gcd(int a, int b){
      if (a == 0)
        return b;
      return gcd(b % a, a);
    }

    int findGCD(vector<int> &arr){
      int result = arr[0];
      for (int i = 1; i < arr.size(); i++){
        result = gcd(arr[i], result);
        if(result == 1) return 1;
      }
      return result;
    }
    
    
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(numsDivide.begin(), numsDivide.end());
        map<int, int> m;
        for (int &n : nums){
            m[n]++;
        }
        
        int gcdOfWholeArray = findGCD(numsDivide);
        int cnt = 0;
        for (auto& pr : m){
            if (gcd(pr.first, gcdOfWholeArray) == pr.first){
                break;
            } else {
                cnt+=pr.second;
            }
        }
        return (cnt == nums.size() ? -1 : cnt);
    }
};
