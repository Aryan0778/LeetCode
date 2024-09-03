class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    int n=nums.size(),a=0,mlen=INT_MIN,sum=0;
    int target=accumulate(nums.begin(),nums.end(),0);
    target-=x;
        if(target<0) return -1;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        while(sum>target){
            sum-=nums[a++];
        }
        if(sum==target) mlen=max(mlen,i-a+1);
    }
        if(mlen==INT_MIN) return -1;
        cout<<mlen;
        return n-mlen;
    }
};