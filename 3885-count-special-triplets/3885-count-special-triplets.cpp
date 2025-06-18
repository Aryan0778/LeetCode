class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(), count = 0;
        map<int, int> mpp2, mpp1;

        for (int i = 0;i<n; i++) {
            mpp2[nums[i]]++;
        }

        mpp1[nums[0]]++;
        mpp2[nums[0]]--;
        if (mpp2[nums[0]] == 0) mpp2.erase(nums[0]);

        for (int i = 1; i < n; i++) {
          mpp2[nums[i]]--;
            if (mpp2[nums[i]] == 0) mpp2.erase(nums[i]);
            if ((mpp1.find(nums[i] * 2) != mpp1.end()) && (mpp2.find(nums[i] * 2) != mpp2.end())) {
              cout<<i<<" ";
              count=(count+(1LL*mpp1[2*nums[i]]*mpp2[2*nums[i]])%MOD)%MOD;
            }

            mpp1[nums[i]]++;
            
        }

        return count;
    }
};
