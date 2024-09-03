class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int n=nums.size(),a=0,len=INT_MAX,sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        while(sum>=target){
            len=min(len,i-a+1);
            sum-=nums[a++];
        }
    }
    return len==INT_MAX?0:len;
    }
};