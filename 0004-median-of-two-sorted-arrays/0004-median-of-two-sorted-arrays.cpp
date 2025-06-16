class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()) swap(nums1,nums2); 
    int m=nums1.size(),n=nums2.size();
    int start=0,end=m;
    double ans=0.0;
    while(start<=end){
        int mid1=(start+end)/2;
        int mid2=((m+n+1)/2)-mid1;
        int l1=(mid1==0)?INT_MIN:nums1[mid1-1];
        int l2=(mid2==0)?INT_MIN:nums2[mid2-1];
        int r1=(mid1==m)?INT_MAX:nums1[mid1];
        int r2=(mid2==n)?INT_MAX:nums2[mid2];
        if(l1<=r2 && l2<=r1){
            ans=max(l1,l2);
            if((m+n)%2==0){
                ans+=min(r1,r2);
                ans/=2.0;
                break;
            }
        }
        if(l1>r2) end=mid1-1;
        else start=mid1+1;
    }
    return ans;
    }
};