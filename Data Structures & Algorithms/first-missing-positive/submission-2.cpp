class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int right = nums.size()-1;
        int n = nums.size();
        // for(int left = 0; left < nums.size(); left++){
        //     if(nums[left] > n || nums[left] <=0 ){
        //        while(nums[right] > n || nums[right] <= 0){
        //          right--;
        //        }
        //        int temp = nums[left];
        //        nums[left] = nums[right];
        //        nums[right] = temp;
        //     }
        // }
        // nums.push_back(n+2);
        // nums.push_back(n+2);
        // nums.push_back(n+2);
        // n = nums.size();
        // for(int i = 0; i < n; i++ ){
        //     if(nums[i] <=0 || nums[i] > n)
        //         nums[i] = n+3;
        // }
        int ans = 1;   
        for(int i = 0; i < nums.size();i++){
            if(nums[i] > 0 &&  nums[i] <=nums.size() && nums[i] !=i+1){
              while(nums[i] != i+1){
                if(nums[nums[i]-1] == nums[i]){
                    break;
                }
               int temp = nums[nums[i] - 1];
               nums[nums[i] - 1] = nums[i];
                 if (temp <= 0 || temp > n) {
                    break;
                }
               nums[i] = temp;

              }                
            }
        }
        for(int i = 0;i < nums.size(); i++){
            if(ans != nums[i]){
                break;
            }
            ans++;
        }
        return ans;
    }
};