class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
    int n=nums.size(),mlen=INT_MAX;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i])!=mpp.end()){
            mlen=min(mlen,i-mpp[nums[i]]+1);
            mpp[nums[i]]=i;
            cout<<mlen<<" ";
            continue;
        }
        mpp[nums[i]]=i;
    }
    return mlen==INT_MAX?-1:mlen;
    }
};