class Solution {
private:
    void heapify(vector<int> &arr, int i, int n){
        int left = (2*i)+1;
        int right = (2*i)+2;
        int largest = i;
        if (left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]){
            largest = right;
        }
        if (largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n/2; i >= 0; i--){
            heapify(nums, i, n);
        }

        for (int i = n-1; i > 0; i--){
            swap(nums[i], nums[0]);
            heapify(nums, 0, i);
        }
        return nums;
    }
};
