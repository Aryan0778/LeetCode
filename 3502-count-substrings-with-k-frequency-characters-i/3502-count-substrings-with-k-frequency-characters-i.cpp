class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size(),a=0,count=0;
        map<char,int>mpp;
        for(int i=0;i<n;i++){
          mpp[s[i]]++;
          while(mpp[s[i]]>=k){
            count+=(n-i);
            mpp[s[a]]--;
            a++;
          }
        }
        return count;
    }
};