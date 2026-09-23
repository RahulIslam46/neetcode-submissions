class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        auto merge = [&](auto&& merge, int low, int mid, int high) -> void {
            vector<int> temp;
            int id1 = low;
            int id2 = mid+1;
            while (id1 <= mid && id2 <= high) {
                if (nums[id1] < nums[id2]) {
                    temp.push_back(nums[id1]);
                    id1++;
                } else {
                    temp.push_back(nums[id2]);
                    id2++;
                }
            }
            for (int i = id1; i <= mid; i++) {
                temp.push_back(nums[i]);
            }
            for (int i = id2; i <= high; i++) {
                temp.push_back(nums[i]);
            }
            for (int i = 0; i < temp.size(); i++) {
                nums[i + low] = temp[i];
            }
        };

        auto divided = [&](auto&& divided, int low, int high) -> void {
            int mid = (low + high) / 2;
            if (low < high) {
                divided(divided, low, mid);
                divided(divided, mid + 1, high);
                merge(merge,low, mid, high);
            }
        };

        int sz = nums.size()-1;
        divided(divided,0,sz);
        return nums;
    }
};