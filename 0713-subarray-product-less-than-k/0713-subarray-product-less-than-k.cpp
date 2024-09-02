class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n=nums.size(),a=0,pro=1,count=0;
    for(int i=0;i<n;i++){
    pro*=nums[i];
    while(a<=i &&pro>=k){
        pro/=nums[a];
        a++;
    }
    count+=(i-a+1);
    }
    return count;
    }
};