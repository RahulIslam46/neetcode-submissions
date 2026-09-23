class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int mid = 0;
        int low = 0;
        int high = nums.size()-1;
        while(mid <= high){
            cout<<mid<<" "<<nums[mid]<<" "<<nums[high]<<endl;
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                //swap(nums[mid],nums[low]);
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
            for(auto it :nums){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
};