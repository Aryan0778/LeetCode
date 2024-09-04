class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int a=0,mlen=INT_MIN;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            while(mpp.size()>2){
                mpp[nums[a]]--;
                if(mpp[nums[a]]==0) mpp.erase(nums[a]);
                a++;
            }
            mlen=max(mlen,i-a+1);
        }
        return mlen;
    }
};