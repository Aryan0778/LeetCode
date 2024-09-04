class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n=nums.size(),a=0,count=0,maxm=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]==0) count++;
        while(count>1){
            if(nums[a]==0) count--;
            a++;
        }
        maxm=max(maxm,i-a+1);
    }
    return maxm-1;
    }
};