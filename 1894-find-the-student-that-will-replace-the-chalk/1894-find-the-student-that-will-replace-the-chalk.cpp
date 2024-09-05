class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        k=k%s;
        for(int i=0;i<n;i++){
            if(nums[i]>k) return i;
            else k-=nums[i];
        }
        return -1;
    }
};