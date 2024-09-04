class Solution {
public:
    int isPossible(int mid,vector<int>&nums){
        map<int,int>mpp;
        int i=0,a=0,n=nums.size();
        for(i=0;i<mid;i++){
            mpp[nums[i]]++;
        }
        bool check=false;
        if(mpp.size()<=2) check=true;
        for(;i<n;i++){
            mpp[nums[i]]++;
            mpp[nums[a]]--;
            if(mpp[nums[a]]==0) mpp.erase(nums[a]);
            a++;
            if(mpp.size()<=2) check=true;
        }
        return check;
    }
    int totalFruit(vector<int>& nums) {
    int n=nums.size();
    int mlen=-1;
    int start=1,end=n;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(mid,nums)){
            mlen=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return mlen;
    }
};