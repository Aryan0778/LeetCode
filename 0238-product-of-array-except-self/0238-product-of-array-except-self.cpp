class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int left=1,right=1;
        vector<int>output(n,1);
        for(int i=0;i<n;i++){
            output[i]*=left;
            left=left*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            output[i]*=right;
            right=right*nums[i];
        }
        return output;
    }
};