class Solution {
public:
    bool isPossible(long long x,vector<int>& nums1, vector<int>& nums2, long long k){
      long long count=0;
      long long n1=nums1.size(),n2=nums2.size();
      for(int i=0;i<n1;i++){
        if(nums1[i]<0){
          long long rem=ceil((double)x/nums1[i]);
          long long ind=lower_bound(nums2.begin(),nums2.end(),rem)-nums2.begin();
          count+=(n2-ind);
        }
        else if(nums1[i]>0){
          long long rem=floor((double)x/nums1[i]);
          long long ind=upper_bound(nums2.begin(),nums2.end(),rem)-nums2.begin();
          count+=ind;
        }
        else{
          if(x>=0){
            count += n2;
          }
        }
        if(count>=k) return true;
      }
      return count>=k;
    } 
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    long long n1=nums1.size(),n2=nums2.size(),start=-1e10,end=1e10,ans=0;
    while(start<=end){
      long long mid=(start+end)/2;
      if(isPossible(mid,nums1,nums2,k)){
        ans=mid;
        end=mid-1;
      }
      else{
        start=mid+1;
      }
    }
    return ans;    
    }
};