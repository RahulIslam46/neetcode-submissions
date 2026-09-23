class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        int ans = num;
        int cur = 1;
        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                num = nums[i];
            }
            if(nums[i]==num){
                count++;
            }else{
                count--;
            }
           
            if(count>cur){
                ans = num;
                cur = count;
            }
            cout<<count<<" "<<ans<<" "<<num<<endl;
        }
        return ans;
        
    }
};