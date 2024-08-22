class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        long long ele=nums[i];
        long long chair=ele-1;
        if(ele>=1 && ele<=n){
            if(nums[chair]!=ele){
            swap(nums[chair],nums[i]);
            i--;
            }
        }
    }
        
        
        
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1) return i+1;
        }
    return n+1;
    }
};