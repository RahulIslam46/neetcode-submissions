class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                k++;
            }
        }
        if(k==0){
            nums.clear();
        }
        int left = 0,right = nums.size() -1 ;
        
        while(left < right){
            if(nums[left] == val){
                while(nums[right] == val){
                    right--;
                }
                if(left>=right){
                    break;
                }
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            left++;
        }
        cout<< k<<endl;
        return k;
    }
};