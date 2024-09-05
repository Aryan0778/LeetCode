class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
    map<int,int>mpp;
    int mlen=INT_MAX,n=nums.size();
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i])!=mpp.end()){
            mlen=min(mlen,i-mpp[nums[i]]+1);
        }
        cout<<i<<" "<<mlen<<endl;
        mpp[nums[i]]=i;
    }
    return mlen==INT_MAX?-1:mlen;    
    }
};